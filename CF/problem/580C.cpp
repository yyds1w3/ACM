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
const int MAXN = 2e5 + 1;
int n, m;
ll ans;
vector<int> adj[MAXN];
int col[MAXN];
void dfs(int u, int fa, int c) {
    if (col[u]){
        c++;
        if (c > m) return;
    }else c = 0;
    if (adj[u].size() == 1) {
        ans++;
        return;
    }
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u, c);
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> col[i];
    adj[1].push_back(0);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
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
