//Sat Aug 15 08:54:05 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> w(n), val(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> val[i];
    }
    for (int i = 0; i < n; ++i) {
        int d;
        std::cin >> d;
        if (d == 0) continue;
        d--;
        adj[d].push_back(i);
    }
    int tot = 0, cnt = 0;
    std::vector<int> dfn(n), low(n), stk, id(n), sccw(n+1), sccv(n+1);
    auto dfs = [&](auto self, int u) -> void {
        dfn[u] = low[u] = ++tot;
        stk.push_back(u);
        for (int v : adj[u]) {
            if (!dfn[v]) {
                self(self, v);
                low[u] = std::min(low[u], low[v]);
            }else if (!id[v]) low[u] = std::min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            cnt++;
            while (true) {
                int x = stk.back();
                stk.pop_back();
                id[x] = cnt;
                sccw[cnt] += w[x];
                sccv[cnt] += val[x];
                if (x == u) break;
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            dfs(dfs, i);
        }
    }
    std::vector<std::vector<int>> adj2(n + 1);
    std::vector<int> in(n + 1);
    for (int i = 0; i < n; ++i) {
        for (int v : adj[i]) {
            if (id[v] != id[i]) {
                adj2[id[i]].push_back(id[v]);
                in[id[v]]++;
            }
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        if (in[i] == 0) {
            adj2[0].push_back(i);
        }
    }
    std::vector dp(cnt+1, std::vector<int>(m + 1));
    auto dfs2 = [&](auto self, int u) -> void {
        for (int v : adj2[u]) {
            self(self, v);
            for (int i = m-sccw[u]; i >= 0; --i) {
                for (int j = 0; j <= i; ++j) {
                    dp[u][i] = std::max(dp[u][i], dp[u][i-j] + dp[v][j]);
                }
            }
        }
        for (int i = m; i >= 0; --i) {
            if (i >= sccw[u]) dp[u][i] = dp[u][i - sccw[u]] + sccv[u];
            else dp[u][i] = 0;
        }
    };
    dfs2(dfs2, 0);
    std::cout << dp[0][m] << nl;
}
