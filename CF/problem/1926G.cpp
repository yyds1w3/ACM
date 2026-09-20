//Sat May 30 02:54:02 PM CST 2026
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
const int INF = 1E9;
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int x;
        std::cin >> x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> dp(n, std::vector<int>(2));
    // dp[u][0] ==> S / C;
    // dp[u][1] ==> P / C;
    auto dfs = [&](auto self, int u, int fa) -> void {
        if (s[u] == 'P') dp[u][0] = INF;
        if (s[u] == 'S') dp[u][1] = INF;
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            if (s[u] != 'P') {
                dp[u][0] += std::min(dp[v][1] + 1, dp[v][0]);
            }
            if (s[u] != 'S') {
                dp[u][1] += std::min(dp[v][0] + 1, dp[v][1]);
            }
        }
    };
    dfs(dfs, 0, 0);
    std::cout << std::min(dp[0][0], dp[0][1]) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
