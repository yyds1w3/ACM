//Wed Apr 22 08:15:10 PM CST 2026
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
const int INF = 1e9;
const int MOD = 100003;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
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
    std::vector<int> dist(n, INF);
    std::vector<int> dp(n);
    std::queue<int> q;
    q.push(0);
    dp[0] = 1;
    dist[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                dp[v] = dp[u];
                q.push(v);
            }else if (dist[u] + 1 == dist[v]) {
                dp[v] = (dp[v] + dp[u]) % MOD;
                // 不入队 // 为什么?
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << dp[i] << nl;
    }

}
