//Thu Aug 13 07:56:59 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
#define debugv(v) {std::cerr << #v << ": "; for (int i = 0; i <= cnt; ++i) std::cerr << v[i] << " "; std::cout << nl;}
using i64 = long long;
using i128 = __int128;
const int N = 1e4;
int n, m;
std::vector<std::vector<int>> adj(N), adj2(N + 1);
int tot = 0, top = -1, cnt = 0;
std::vector<int> a(N);
std::vector<int> dfn(N), low(N), stk(N), id(N);
std::vector<int> scc(N + 1);
std::vector<int> dp(N + 1, -1);
void dfs(int u) {
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;
    for (int v : adj[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        }else if (!id[v]){
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        cnt++;
        while (top >= 0) {
            int x = stk[top--];
            id[x] = cnt;
            scc[cnt] += a[x];
            if (x == u) break;
        }
    }
};
void dfs2(int u){
    if (dp[u] != -1) return;
    dp[u] = scc[u];
    for (int v : adj2[u]) {
        dfs2(v);
        dp[u] = std::max(dp[u], scc[u] + dp[v]);
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int v : adj[i]) {
            if (id[i] != id[v]) {
                adj2[id[i]].push_back(id[v]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (dp[i] == -1) {
            dfs2(i);
            ans = std::max(ans, dp[i]);
        }
    }
    std::cout << ans << nl;
}
