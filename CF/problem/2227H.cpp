//Sat Jun 20 01:05:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 0;
    int edges = 0;
    std::vector<int> cnt(n);
    std::vector<int> leafs;
    if (adj[root].size() == 1) leafs.push_back(root);
    auto dfs1 = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            cnt[u] += cnt[v];
        }
        if (u != root && adj[u].size() == 1) {
            cnt[u] = 1;
            leafs.push_back(u);
        }

        if (u != root && cnt[u] % 2 == 1) {
            edges++;
        }
    };
    dfs1(dfs1, root, root);
    std::vector<int> mx(n);
    auto dfs2 = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) if (v != fa) {
            if (cnt[v] % 2 == 1) {
                mx[v] = mx[u] + 1;
            }else {
                mx[v] = mx[u] - 1;
            }
            self(self, v, u);
        }
    };
    dfs2(dfs2, root, root);
    if (leafs.size() % 2 == 0) {
        std::cout << edges << nl;
    }else {
        int diff = -1e9; 
        for (int leaf : leafs) {
            diff = std::max(diff, mx[leaf]);
        }
        std::cout << edges - diff << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
