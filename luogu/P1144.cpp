#include <bits/stdc++.h>
#include <queue>
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
const int MOD = 1e5 + 3;
const int MAXN = 1e6 + 5;
vector<int> adj[MAXN];
int dist[MAXN];
int cnt[MAXN];
int n, m;
void bfs() {
    rep(i, 1, n) {
        dist[i] = INF;
        cnt[i] = 0;
    }
    dist[1] = 0;
    cnt[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            }else if (dist[v] == dist[u] + 1) {
                cnt[v] = (cnt[u] + cnt[v]) % MOD;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    rep(i, 1, n) cout << cnt[i] % MOD << nl;
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
