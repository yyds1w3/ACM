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
const int MAXN = 1e6 + 1;
vector<pair<int, int>> adj[MAXN];
int sz[MAXN];
int n;
ll ans;
void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto e : adj[u]) {
        int v = e.first;
        int w = e.second;
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        ll diff = abs(2 * sz[v] - n);
        ans += (ll)w*diff;
    }
}
void solve() {
    int a, b, c; cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(1,0);
    cout << ans << "\n";
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
