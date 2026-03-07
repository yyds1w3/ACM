#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXN = 16005;
int w[MAXN];
vector<int> adj[MAXN];
int dp[MAXN];
int ans = -2e9;
void dfs(int u, int fa) {
    dp[u] = w[u];
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (dp[v] > 0) dp[u] += dp[v];
    }
    ans = max(ans, dp[u]);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1, u, v; i <= n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << nl;
}
