#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e4 + 5;
vector<int> adj[MAXN];
int dfn[MAXN], low[MAXN];
int timer;
bool is_cut[MAXN];
vector<int> ans;
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++timer;
    int child = 0;
    for (int v : adj[u]) {
        if (v == fa) continue;
        if (!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa != 0 && low[v] >= dfn[u] && !is_cut[u]) {
                is_cut[u] = true;
                ans.push_back(u);
            }
        }else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (fa == 0 && child >= 2 && !is_cut[u]) {
        is_cut[u] = true;
        ans.push_back(u);
    }
}
void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n) {
        if (!dfn[i]) tarjan(i, 0);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (int as : ans) cout << as << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
