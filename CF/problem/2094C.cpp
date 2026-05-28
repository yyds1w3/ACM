//Thu May 14 12:10:24 PM CST 2026
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
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> a[i][j];
            }
        }
        std::vector<int> p(2 * n);
        std::vector<bool> vis(2 * n + 1);
        for (int i = 0; i < n; ++i) {
            p[i + 1] = a[i][0];
            vis[a[i][0]] = true;
        }
        for (int j = 1; j < n; ++j) {
            p[n + j] = a[n - 1][j];
            vis[a[n-1][j]] = true;
        }
        for (int i = 1; i <= 2 * n; ++i) {
            if (!vis[i]) {
                p[0] = i;
                break;
            }
        }
        for (int i = 0; i < 2 * n; ++i) {
            std::cout << p[i] << " ";
        }
        std::cout << nl;
    }
}
