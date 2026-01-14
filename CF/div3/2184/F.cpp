#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dp[MAXN];
void dfs(int u, int fa) {
    bool leaf = true;
    dp[u] = 0b001;
    for (int v : adj[u]) {
        if (v == fa) continue;
        leaf = false;
        dfs(v, u);
        int nxt_mask = 0;
        for (int i = 0; i < 3; ++i) {
            if ((dp[u] >> i) & 1) {
                for (int j = 0; j < 3; ++j) {
                    if ((dp[v] >> j) & 1) {
                        nxt_mask |= (1 << ((i + j) % 3));
                    }
                }
            }
        }
        dp[u] = nxt_mask;
    }
    if (leaf) {
        dp[u] = 0b010;
    }else {
        dp[u] |= 0b010;
    }
    
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    memset(dp+1, 0, n * sizeof(int));
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1] & 1 ? "YES" : "NO") << nl;
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
