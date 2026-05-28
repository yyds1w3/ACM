//Wed May 20 06:34:38 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> p(n + 1);
    if (n & 1) {
        for (int i = (n + 1) / 2; i <= n; ++i) {
            p[i] = i - n / 2;
        }
        for (int i = 1; i < (n + 1) / 2; ++i) {
            p[i] = i + (n + 1) / 2;
        }
        for (int i = 1; i <= n; ++i) {
            std::cout << p[i] << " ";
        }
        std::cout << nl;
    }else {
        for (int i = 1; i <= n; ++i) {
            if (i <= n / 2) {
                p[i] = i + n / 2;
            }else {
                p[i] = i - n / 2;
            }
        }
        for (int i = 1; i <= n; ++i) {
            std::cout << p[i] << " ";
        }
        std::cout << nl;
    }
}
