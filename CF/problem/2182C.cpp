//Sat May  2 12:51:58 PM CST 2026
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
        std::vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> c[i];
        }
        i64 ans = 0;
        // 解耦
        int pa = 0;
        for (int off1 = 0; off1 < n; ++off1) {
            bool f = true;
            for (int j = 0; j < n; ++j) {
                if (a[(j + off1) % n] >= b[j]) {
                    f = false;
                    break;
                }
            }
            if (f) pa++;
        } 
        int pb = 0;
        for (int off2 = 0; off2 < n; ++off2) {
            bool f = true;
            for (int j = 0; j < n; ++j) {
                if (c[(j + off2) % n] <= b[j]) {
                    f = false;
                    break;
                }
            }
            if (f) pb++;
        } 
        ans = 1LL * pa * pb * n;
        std::cout << ans << nl;
    }
}
