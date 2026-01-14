#include <bits/stdc++.h>
#include <queue>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
struct st {
    int to;
    ll w;
    bool operator<(const st& other) const {return w > other.w;}
};
vector<st> adj[MAXN];
ll dist[MAXN];
int fa[MAXN];
void dji() {
    priority_queue<st> pq;
    fill(dist, dist + MAXN, LINF);
    dist[1] = 0;
    pq.push({1, 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.to;
            ll w = edge.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                fa[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }

}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dji();
    if (dist[n] == LINF) cout << -1 << nl;
    else {
        vector<int> path;
        while (n != 0) {
            path.push_back(n);
            n = fa[n];
        }
        reverse(path.begin(), path.end());
        for (int v : path) cout << v << " ";
        cout << nl;
    }
    
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
