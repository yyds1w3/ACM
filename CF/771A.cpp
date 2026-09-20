//Fri Aug 21 07:39:15 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    std::vector<int> cmp;
    std::vector<bool> vis(n);
    auto dfs = [&](auto self, int u) -> void {
        vis[u] = true;
        cmp.push_back(u);
        for (int v : adj[u]) if (!vis[v]) {
            self(self, v);
        }
    };
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cmp.clear();
            dfs(dfs, i);
            for (int j = 0; j < (int)cmp.size(); ++j) {
                if (deg[cmp[j]] != (int)cmp.size() - 1) {
                    ok = false;
                }
            }
            if (!ok) break;
        }
    }
    if (ok) {
        std::cout<< "YES" << nl;
    }else {
        std::cout << "NO" << nl;
    }
}
