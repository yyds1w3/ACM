#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector adj(n, std::vector<int>());
        std::vector<int> color(n, -1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                std::vector<int> cl(2);
                bool ok = true;
                auto dfs = [&](auto self, int u, int c) -> void {
                    color[u] = c;
                    cl[c]++;
                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            self(self, v, 1 ^ c);
                        }else if (color[v] == color[u]) {
                            ok = false;
                        }
                    }
                };
                dfs(dfs, i, 0);
                if (ok) {
                    ans += std::max(cl[0], cl[1]);
                }
            }
        }
        std::cout << ans << nl;
    }
}
