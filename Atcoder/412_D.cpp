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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<bool>> adj(n, std::vector<bool>(n));
    for (int i = 0;i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u][v] = adj[v][u] = true;
    }
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    auto getK = [&](int l, int r) -> int {
        int k = 0;
        for (int i = l; i < r; ++i) {
            if (adj[p[i]][(i ==  r - 1 ? p[l] : p[i + 1])] == true) {
                k++;
            }
        }
        return k;
    };
    int ans = 100;
    do {
        if (n >= 3) {
            int k = getK(0, n);
            ans = std::min(ans, n + m - 2 * k); // m - k + n - k
            for (int d = 3; d <= n - 3; ++d) {
                int k = getK(0, d) + getK(d, n);
                ans = std::min(ans, m + n - 2 * k);
            }
        }
    }while (std::next_permutation(p.begin(), p.end()));
    std::cout << ans << nl;
}
