//Mon Aug 17 10:58:05 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int v;
        std::cin >> v;
        v--;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    int m;
    std::cin >> m;
    std::vector<bool> need(n);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        x--;
        need[x] = true;
    }
    std::vector<int> ans;
    auto dfs = [&](auto self, int u, int fa) -> int {
        int res = need[u];
        for (int v : adj[u]) if (v != fa){
            int res1 = self(self, v, u);
            if (res1) {
                if (res) {
                    ans.push_back(v);
                }else {
                    res = 1;
                }
            }
        }
        return res;
    };
    dfs(dfs, 0, -1);
    int sz = ans.size();
    std::cout << sz << " ";
    for (int i = 0; i < sz; ++i) {
        std::cout << ans[i] + 1 << " ";
    }
    std::cout << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
