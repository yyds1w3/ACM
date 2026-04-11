#include <iostream>
#include <vector>
#include <algorithm>
#define nl "\n"
using i64 = long long;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> sz(n);
    std::vector<int> ans;
    int mn = 1e9;
    auto dfs = [&](auto self, int fa, int u) -> void {
        sz[u] = 1;
        int res = 0;
        for (int v : adj[u]) {
            if (v == fa) continue;
            self(self, u, v);
            sz[u] += sz[v];
            res = std::max(res, sz[v]);
        }
        res = std::max(res, n - sz[u]);
        if (res < mn) {
            ans.clear();
            ans.push_back(u);
            mn = res;
        }else if (res == mn) {
            ans.push_back(u);
        }
    };
    dfs(dfs, -1, 0);
    std::sort(ans.begin(), ans.end());
    for (int i = 0, sz = ans.size(); i < sz; ++i) {
        std::cout << ans[i] + 1 << (i == sz - 1 ? "" : " ");
    }
}
