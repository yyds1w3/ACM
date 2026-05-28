//Fri May  1 05:23:46 PM CST 2026
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
        std::vector<i64> f(n), a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> f[i];
        }
        for (int i = 1; i < n - 1; ++i) {
            a[i] = (f[i + 1] + f[i - 1] - 2 * f[i]) / 2;
        }
        a[0] = f[n - 1];
        for (int i = 1; i < n - 1; ++i) {
            a[0] -= (n - 1 - i) * a[i];
        }
        a[0] /= n - 1;
        a[n-1] = f[0];
        for (int i = 1; i < n - 1; ++i) {
            a[n-1] -= i * a[i];
        }
        a[n-1] /= n - 1;
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << nl;
    }
}
