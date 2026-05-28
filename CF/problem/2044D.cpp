//Thu May 14 07:05:48 PM CST 2026
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
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int b = 1;
        std::vector<bool> vis(n + 1);
        for (int i = 0; i < n; ++i) {
            if (!vis[a[i]]) {
                std::cout << a[i] << " ";
                vis[a[i]] = true;
            }else {
                while (vis[b]) {
                    b++;
                }
                std::cout << b << " ";
                vis[b] = true;
                b++;
            }
        }
        std::cout << nl;
    }
}
