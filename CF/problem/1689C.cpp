#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 3e5 + 5;
int sz[MAXN];
int dp[MAXN];
vector<int> adj[MAXN];
void dfs(int u, int fa) {
    sz[u] = 1;
    dp[u] = 0; // u被感染后的能救的最大节点数
    int tot = 0;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        tot += dp[v];
        sz[u] += sz[v]; 
    }
    for (int v : adj[u]) {
        if (v == fa) continue;
        dp[u] = max(dp[u], tot - dp[v] + sz[v] - 1);
    }
    
}
void solve() {  
    int n; cin >> n;
    rep(i, 1, n) adj[i].clear();
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
