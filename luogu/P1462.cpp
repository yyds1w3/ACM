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
const int MAXN = 2e5 + 5;
int n, m, b;
int f[MAXN];
struct Edge {
    ll to, w;
    bool operator<(const Edge& other) const {return w > other.w;}
};
vector<Edge> adj[MAXN];
ll dist[MAXN];
bool check(int x) {
    rep(i, 1, n) dist[i] = INF;
    dist[1] = 0;
    priority_queue<Edge> pq;
    pq.push({1, 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            if (f[v] > x) continue;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist[n] <= b;
}
void solve() {
    cin >> n >> m >> b;
    int mn = INF;
    rep(i, 1, n) cin >> f[i];
    rep(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int l = f[1], r = 1e9 + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }else l = mid + 1;
    }
    if (l == 1e9 + 1) cout << "AFK" << nl;
    else cout << l << nl;
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
