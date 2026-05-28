//Thu Apr 30 04:39:52 PM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> c(n), p(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> c[i] >> p[i];
        }
        double E = 0;

        for (int i = n - 1; i >= 0; --i) {
            E = std::max(E, c[i] + E * (100 - p[i]) / 100);
        }
        std::cout << std::setprecision(6) << std::fixed << E << nl;
    }
}
