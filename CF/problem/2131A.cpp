//Fri May 15 08:12:24 PM CST 2026
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
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                c1 += a[i] - b[i];
            }else {
                c2 += b[i] - a[i];
            }
        }
        std::cout << c1 + 1 << nl;
    }
}
