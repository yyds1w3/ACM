//Sun Apr 26 08:24:45 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(1001));
    auto dfs = [&](auto self, int u, int fa) -> void {
        bool leaf = true;
        for (int v : adj[u]) {
            if (v == fa) continue;
            leaf = false;
            self(self, v, u);
        }
        if (leaf) {
            dp[u][0] = 1;
            dp[u][w[u]] = 1;
        }else {
            dp[u][0] = 1;
            for (int v : adj[u]) {
                if (v == fa) continue;
                std::vector<int> nxt(1001);
                for (int i = 0; i <= w[u]; ++i) {
                    if (!dp[u][i]) continue;
                    for (int j = 0; j <= w[v]; ++j) {
                        if (i + j <= w[u]) nxt[i + j] |= dp[v][j];
                    }
                }
                dp[u] = nxt;
            }
        }
    };
    dfs(dfs, 0, 0);
    int mx = 0;
    for (int i = w[0]; i >= 0; --i) {
        if (dp[0][i] == true) {
            mx = i;
            break;
        }
    }
    std::cout << mx << nl;
}
