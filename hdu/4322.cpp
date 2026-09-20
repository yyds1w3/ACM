//Sat Aug  8 12:38:39 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
double dp[2501][2501];
int sz[2501];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int k, n;
    std::cin >> k >> n;
    k++;
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> cost(n + 1), fight(n + 1);
    for (int i = 1; i <= n; ++i) {
        int v;
        std::cin >> cost[i] >> fight[i] >> v;
        adj[v].push_back(i);
    }
    auto dfs = [&](auto self, int u, double x) -> void {
        sz[u] = 1;
        dp[u][0] = 0;
        dp[u][1] = fight[u] - x * cost[u];
        for (int v : adj[u]) {
            self(self, v, x);

            for (int i = std::min(k, sz[u] + sz[v]); i >= 1; --i) {
                for (int j = std::max(0, i - sz[u]); j <= std::min(sz[v], i-1); ++j) {
                    dp[u][i] = std::max(dp[u][i], dp[u][i-j] + dp[v][j]);
                }
            }
            sz[u] += sz[v];
        }
    };
    auto check = [&](double x) -> bool {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = -2e18;
            }
        }
        memset(sz, 0, sizeof(sz));
        dfs(dfs, 0, x);
        return dp[0][k] >= 0;
    };
    double l = 0, r = 10000;
    for (int i = 0; i < 30; ++i) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    std::cout << std::setprecision(3) << std::fixed << l << nl;

}
