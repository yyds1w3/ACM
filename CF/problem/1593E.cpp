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
const int MAXN = 4e5 + 5;
vector<int> adj[MAXN];
int deg[MAXN];
int d[MAXN];
int tot;
void solve() {
    int n, k; cin >> n >> k;
    rep(i, 1, n) {adj[i].clear(); deg[i] = 0;}
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    tot = 0;
    rep(i, 1, n) if (deg[i] <= 1) d[++tot] = i;
    int start = 1;
    rep(i, 1, k - 1) {
        int end = tot;
        rep(u, start, end) {
            for (int v : adj[d[u]]) {
                deg[v]--;
                if (deg[v] == 1) d[++tot] = v;
            }
        }
        start = end + 1;
    }
    cout << n - tot << nl;
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
