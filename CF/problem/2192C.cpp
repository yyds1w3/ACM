//Fri May  1 08:34:40 PM CST 2026
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
        int n, h, k;
        std::cin >> n >> h >> k;
        std::vector<int> a(n);
        std::vector<int> premn(n), sufmx(n);
        std::vector<i64> pi(n);
        i64 tot = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (i > 0) {
                premn[i] = std::min(premn[i-1], a[i]);
            }else {
                premn[i] = a[i];
            }
            tot += a[i];
            pi[i] = tot;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1) {
                sufmx[i] = std::max(a[i], sufmx[i+1]);
            }else {
                sufmx[i] = a[i];
            }
        }
        i64 ans = 0;
        ans += (h / tot) * (n + k);
        h %= tot;
        if (h == 0) {
            std::cout << ans - k << nl;
        }else {
            bool killed = false;
            for (int i = 0; i < n - 1; ++i) {
                if (pi[i] + std::max(0, sufmx[i + 1] - premn[i]) >= h) {
                    std::cout << ans + i + 1 << nl;
                    killed = true;
                    break;
                }
            }
            if (!killed) {
                std::cout << ans + n << nl;
            }
        }
    }
}
