//Fri Aug 21 06:33:24 PM CST 2026
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
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<bool> vis(n);
    int ans = 0;
    auto dfs = [&](auto self, int u, int fa, int c) -> int {
        vis[u] = true;
        for (int v : adj[u]) if (v != fa) {
            if (!vis[v]) {
                self(self, v, u, c);
            }else{
                c++;
            }
        }
        return c;
    };
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            if (dfs(dfs, i, -1, 0) == 1) ans++;
        }
    }
    std::cout << ans << nl;

}
