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
struct Edge {
    int to, w;
};
vector<Edge> adj[MAXN];
int dist[MAXN];
int cnt[MAXN];
bool in_q[MAXN];
int n, m;
bool spfa() {
    rep(i, 1, n) {
        dist[i] = INF;
        cnt[i] = 0;
        in_q[i] = false;
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_q[u] = false;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return true;
                if (!in_q[v]) {
                    in_q[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    rep(i, 1, n) adj[i].clear();
    rep(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        if (w >= 0 ) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }else adj[u].push_back({v, w});
    }
    if (spfa()) cout << "YES" << nl;
    else cout << "NO" << nl;
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
