//Wed Aug 12 09:06:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int MOD = 80112002;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> in(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        in[v]++;
    }
    std::queue<int> q;
    std::vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (adj[u].empty()) ans = (ans + dp[u]) % MOD;
        for (int v : adj[u]) {
            in[v]--;
            dp[v] = (dp[v] + dp[u]) % MOD;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    std::cout << ans << nl;
}
