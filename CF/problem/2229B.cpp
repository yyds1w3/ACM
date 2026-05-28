//Sat May 23 10:38:32 PM CST 2026
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
        std::vector<i64> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        i64 mx = 0;
        i64 tot = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                std::swap(a[i], b[i]);
            }
            mx = std::max(mx, a[i]);
            tot += b[i];
        }
        tot += mx;
        std::cout << tot << nl;
    }
}
