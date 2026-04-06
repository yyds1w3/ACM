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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> fa(n, -1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        fa[y] = x;
    }
    for (int i = 0; i < k; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int u;
            std::cin >> u;
            u--;
            int target = a[u];
            while (true) {
                if (fa[u] != -1) {
                    int g = std::gcd(target, a[fa[u]]);
                    if (g != 1) {
                        std::cout << fa[u] + 1 << nl;
                        break;
                    }else {
                        u = fa[u];
                    }
                }else {
                    std::cout << -1 << nl;
                    break;
                }
            }
        }else {
            int u, val;
            std::cin >> u >> val;
            u--;
            a[u] = val;
        }
    }
}
