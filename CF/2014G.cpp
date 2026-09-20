//Sat Aug 29 03:03:52 PM CST 2026
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
    i64 cap, date;
    bool operator<(const st& other)const{
        return date < other.date;
    }
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int ans = 0;
    int cur = 0;
    std::vector<std::array<int, 2>> v;
    auto work = [&](int d) {
        while (!v.empty() && cur < d) {
            auto &[x, a] = v.back();
            if (cur > x + k - 1) {
                v.pop_back();
                continue;
            }
            if (a >= m) {
                int r = std::min({cur + a / m - 1, x + k - 1, d - 1});
                ans += r - cur + 1;
                a -= (r - cur + 1) * m;
                cur = r + 1;
                continue;
            }
            int need = m;
            while (!v.empty() && need > 0) {
                auto &[x, a] = v.back();
                if (cur > x + k - 1) {
                    v.pop_back();
                    continue;
                }
                if (a <= need) {
                    need -= a;
                    v.pop_back();
                } else {
                    a -= need;
                    need = 0;
                }
            }
            if (need == 0) {
                ans++;
            }
            cur++;
        }
        cur = d;
    };
    for (int i = 0; i < n; i++) {
        int d, a;
        std::cin >> d >> a;
        work(d);
        v.push_back({d, a});
    }
    work(1E9);
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
