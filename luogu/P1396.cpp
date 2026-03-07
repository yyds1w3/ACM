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
const int MOD = 1e9 + 7;
const int MAXN = 2e4 + 5;
struct Edge {
    int to, w;
    bool operator<(const Edge& other) const {return w < other.w;}
};
int dist[MAXN];
vector<Edge> adj[MAXN];
void solve() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    rep(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<Edge> pq;
    rep(i, 1, n) dist[i] = INF;
    dist[s] = 0;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            int value = max(dist[u], w);
            if (value < dist[v]) {
                dist[v] = value; 
                pq.push({v, dist[v]});
            }
        }
    }
    cout << dist[t] << nl;
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
