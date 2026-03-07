#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXN = 3e3 + 5;
struct Edge {
    int to, w;
};
vector<Edge> adj[MAXN];
int money[MAXN];
int dp[MAXN][MAXN];
int sz[MAXN];
int n, m;
void dfs(int u) {
    for (int i = 1; i <= n; ++i) dp[u][i] = -1e9;
    dp[u][0] = 0;
    if (u >= n - m + 1) {
        sz[u] = 1;
        dp[u][1] = money[u - (n - m)];
    }else {
        sz[u] = 0;
        for (auto [v, w] : adj[u]) {
            dfs(v);
            for (int j = sz[u] + sz[v]; j >= 1; j--) {
                for (int k = max(1, j - sz[u]); k <= min(j, sz[v]); k++) {
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - w);
                }
            }
            sz[u] += sz[v];
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    cin >> n >> m;
    for (int i = 1, k, a, c; i <= n - m; i++) {
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            cin >> a >> c;
            adj[i].push_back({a, c});
        }
    }
    for (int i = 1; i <= m; ++i) cin >> money[i];
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= sz[1]; ++i) {
        if (dp[1][i] >= 0) {
            ans = i;
        }
    }
    cout << ans << nl;
}
