//Sun May 17 07:26:25 PM CST 2026
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
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> dist(n, -1);
    std::queue<int> q;
    std::vector<int> ans(k + 1, 1e9);
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (ans[a[u]] == 1e9) {
            ans[a[u]] = dist[u];
        }else {
            ans[a[u]] = std::max(ans[a[u]], dist[u]);
        }
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        std::cout << ans[i] << " ";
    }
}
