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
const int MAXN = 1e5 + 1;
const int INF = 0x3f3f3f3f;
int dist[MAXN];
vector<int> adj[MAXN];
void dfs(int u, int p, int d) {
    dist[u] = d;
    for (int v : adj[u]) {
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u, d+1);
    }
}
void solve() {
    int n, d; cin >> n >> d;
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] <= d) cnt++;
    }
    cout << cnt - 1 << endl;
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
