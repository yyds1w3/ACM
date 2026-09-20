//Thu Aug 13 12:33:42 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    std::vector<bool> ban(n);
    std::vector<int> p(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> p[i];
        p[i]--;
        ban[p[i]] = true;
    }
    std::vector<bool> vis(n);
    std::queue<int> que;
    vis[0] = true;
    if (!ban[0]) {
        que.push(0);
    }
    auto bfs = [&]() -> void {
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : adj[u]) {
                if (vis[v] == true) continue;
                vis[v] = true;
                if (!ban[v]) {
                    que.push(v);
                }
            }
        }
    };
    bfs();
    if (vis[n-1]) {
        std::cout << "YES" << nl;
        return;
    }
    for (int k = q - 1; k >= 0; --k) {
        ban[p[k]] = false;
        if (vis[p[k]]) {
            que.push(p[k]);
            bfs();
        }
        if (vis[n - 1]) {
            std::cout << k << nl;
            return;
        }
    }
    std::cout << "NO" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
