#include <bits/stdc++.h>
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
const int MAXN = 1e4 + 5;
struct Edge {
    int to, w;
};
struct Node {
    int u, cost, k;
    bool operator<(const Node& other)const {return cost > other.cost;}
};
vector<Edge> adj[MAXN];
int dist[MAXN][15];
int n, m, k, s, t; 
void dji() {
    rep(i, 0, n-1) {
        rep(j, 0, k) {
            dist[i][j] = INF;
        }
    }
    dist[s][0] = 0;
    priority_queue<Node> pq;
    pq.push({s, 0, 0});
    while (!pq.empty()) {
        auto [u, d, j] = pq.top();
        pq.pop();
        if (d > dist[u][j]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u][j] + w < dist[v][j]) {
                dist[v][j] = dist[u][j] + w;
                pq.push({v, dist[v][j], j});
            }
            if (j < k && dist[u][j] < dist[v][j+1]) {
                dist[v][j+1] = dist[u][j];
                pq.push({v, dist[v][j+1], j+1});
            }
        }
    }
}
void solve() {
    cin >> n >> m >> k >> s >> t;
    rep(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dji();
    int ans = INF;
    rep(i, 0, k) ans = min(ans, dist[t][i]);
    cout << ans << nl;
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
