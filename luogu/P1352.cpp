#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXN = 6e3 + 5;
int w[MAXN];
vector<int> adj[MAXN];
int dp[MAXN][2];
int in[MAXN];
void dfs(int u) {
    dp[u][1] = w[u];
    dp[u][0] = 0;
    for (int v : adj[u]) {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1, u, v; i <= n-1; ++i) {
        cin >> u >> v;
        adj[v].push_back(u);
        in[u]++;
    }
    int root = 1;
    for (int i = 1; i <= n; ++i) if (in[i] == 0) {root = i; break;}
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << nl;
}
