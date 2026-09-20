//Fri Aug 28 11:58:16 AM CST 2026
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

void solve() {
    i64 n, x;
    std::cin >> n >> x;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    auto ck = [&](i64 h) -> bool {
        i64 res = 0;
        for (int i = 0; i < n; ++i) {
            res += std::max(0LL, h - a[i]);
            if (res > x) return false;
        }
        return true;
    };
    i64 l = 1, r = 1e18;
    while (l < r) {
        i64 mid = (l + r + 1) / 2;
        if (ck(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    std::cout << l << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
