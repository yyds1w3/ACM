//Wed Aug 12 07:36:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int MOD = 10000;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m, s, t0, t1;
    std::cin >> n >> m >> s >> t0 >> t1;
    s--, t0--;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector<std::pair<int, int>> dp(n);
    std::vector<int> in(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        in[v]++;
    }
    std::queue<int> q;
    q.push(s);
    dp[s] = {1, 0};
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            dp[v].first = (dp[v].first + dp[u].first) % MOD;
            dp[v].second = (dp[v].second + dp[u].second + dp[u].first * w) % MOD;
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    std::cout << (dp[t0].second + t1 * (dp[t0].first - 1)) % MOD << nl;
}
