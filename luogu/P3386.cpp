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
    int n, m, e;
    std::cin >> n >> m >> e;
    std::vector adj(n, std::vector<int>());
    for (int i = 0; i < e; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    std::vector<int> match(m, -1);
    std::vector<int> vis(m, -1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto dfs = [&] (auto self, int u) -> bool {
            for (int v : adj[u]) {
                if (vis[v] == i) continue;
                vis[v] = i;
                if (match[v] == -1 || self(self, match[v])) {
                    match[v] = u;
                    return true;
                }
            }
            return false;
        };
        if (dfs(dfs, i)) {
            ans++;
        }
    }
    std::cout << ans << nl;
}
