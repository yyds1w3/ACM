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
const int MAXN = 1e5 + 5;
int L[MAXN], R[MAXN];
vector<int> adj[MAXN];
ll dp[MAXN][2];
void dfs(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] += max(abs(L[u] - L[v]) + dp[v][0], abs(L[u] - R[v]) + dp[v][1]);
        dp[u][1] += max(abs(R[u] - L[v]) + dp[v][0], abs(R[u] - R[v]) + dp[v][1]);
    }
}
void solve() {
    int n, u, v; cin >> n;
    rep(i, 1, n) {dp[i][0] = dp[i][1] = 0; adj[i].clear();}
    rep(i, 1, n) cin >> L[i] >> R[i];
    rep(i, 1, n-1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << nl;
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
