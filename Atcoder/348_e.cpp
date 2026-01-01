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
vector<int> adj[MAXN];
int dep[MAXN];
ll dp[MAXN];
ll w[MAXN];
int c[MAXN];
int n;
ll mn, total_w;
void dfs1(int u, int fa) {
    w[u] = c[u];
    dep[u] = dep[fa] + 1;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        w[u] += w[v];
    }
}
void dfs2(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa) continue;
        dp[v] = dp[u] + total_w - w[v] * 2;
        mn = min(mn, dp[v]);
        dfs2(v, u);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    dep[0] = -1;
    dfs1(1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[1] += (ll)dep[i] * c[i];
    }
    mn = dp[1];
    total_w = w[1];
    dfs2(1, 0);
    cout << mn << endl;

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
