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
const int MAXN = 2e5 + 1;
vector<int> adj[MAXN];
int dep_cnt[MAXN];
int ans;
int mx_dep;
void dfs(int u, int fa, int d) {
    ans = max(ans,(int)adj[u].size());
    mx_dep = max(mx_dep, d);
    dep_cnt[d]++;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u, d+1);
    }
}
void solve() {
    int n; cin >> n;
    ans = 0;
    mx_dep = 0;
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        dep_cnt[i] = 0;
    }
    adj[1].push_back(0);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= mx_dep; ++i) ans = max(ans, dep_cnt[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
