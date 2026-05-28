//Sun Apr 19 04:18:23 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    i64 n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<i64, i64, i64>> v(m);
    for (int i = 0; i < m; ++i) {
        i64 a, b;
        std::cin >> a >> b;
        v[i] = {a - b, a, b};
    }
    std::sort(v.begin(), v.end());
    i64 ans = 0;
    for (auto [d, a, b] : v) {
        if (n < a) continue;
        i64 x = (n - a) / d + 1;
        ans += x;
        n -= x * d;
    }
    std::cout << ans << nl;
}
