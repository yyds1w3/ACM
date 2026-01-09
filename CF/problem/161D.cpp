#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 5e4 + 1;
const int MAXK = 501;
vector<int> adj[MAXN];
int dp[MAXN][MAXK];
ll ans;
int n, k;
void dfs(int u, int fa) {
    dp[u][0] = 1;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (int j = 0; j < k; ++j) ans += dp[u][j] * dp[v][k-1-j]; 
        for (int j = 0; j < k; ++j) dp[u][j + 1] += dp[v][j];
    }
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
