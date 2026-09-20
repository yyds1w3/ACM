//Fri Aug 28 03:12:44 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}
const i64 INF = 2e18;
void solve() {
    i64 a, n;
    std::cin >> a >> n;
    i64 b = a;
    std::vector<int> d(n+1), d0;
    for (int i = 1; i <= n; ++i) std::cin >> d[i];
    if (a == 0) d0.push_back(0);
    while (a) {
        d0.push_back(a % 10);
        a /= 10;
    }
    int m = d0.size();
    i64 ans = INF;
    if (m > 1) {
        i64 res = 0;
        for (int i = 0; i < m - 1; ++i) res = res * 10 + d.back();
        ans = std::min(ans, std::abs(res - b));
    }
    {
        i64 res = 0;
        int first_digit = -1;
        for (int i = 1; i <= n; ++i) {
            if (d[i] > 0) { first_digit = d[i]; break; }
        }
        if (first_digit != -1) {
            res = first_digit;
            for (int i = 0; i < m; ++i) res = res * 10 + d[1];
            ans = std::min(ans, std::abs(res - b));
        }
    }

    auto dfs = [&](auto self, int pos, int op, i64 res) -> void {
        if (pos == -1) {
            ans = std::min(ans, std::abs(res - b));
            return;
        }
        int target = d0[pos];
        if (op == 0) {
            self(self, pos - 1, 0, res * 10 + d.back());
        } else if (op == 2) {
            self(self, pos - 1, 2, res * 10 + d[1]);
        } else {
            int max_less = -1, min_greater = -1;
            bool has_equal = false;

            for (int i = 1; i <= n; ++i) {
                if (d[i] < target) max_less = d[i];
                if (d[i] == target) has_equal = true;
                if (d[i] > target && min_greater == -1) min_greater = d[i];
            }
            if (has_equal) self(self, pos - 1, 1, res * 10 + target);
            if (max_less != -1) self(self, pos - 1, 0, res * 10 + max_less);
            if (min_greater != -1) self(self, pos - 1, 2, res * 10 + min_greater);
        }
    };
    dfs(dfs, m - 1, 1, 0);
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
