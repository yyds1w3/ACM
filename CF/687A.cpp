//Fri Aug 21 08:29:20 PM CST 2026
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
    std::vector<int> col(n, -1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool f = true;
    std::vector<int> pt(2);
    auto dfs = [&](auto self, int u, int c) -> void {
        col[u] = c;
        pt[c]++;
        for (int v : adj[u]) {
            if (col[v] == -1) {
                self(self, v, c ^ 1);
            }else if (col[v] == col[u]) {
                f = false;
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            dfs(dfs, i, 0);
        }
    }
    if (f) {
        std::cout << pt[0] << nl;
        for (int i = 0; i < n; ++i) {
            if (col[i] == 0) std::cout << i + 1 << " ";
        }
        std::cout << nl;
        std::cout << pt[1] << nl;
        for (int i = 0; i < n; ++i) {
            if (col[i] == 1) std::cout << i + 1 << " ";
        }
        std::cout << nl;
    }else {
        std::cout << -1 << nl;
    }
}
