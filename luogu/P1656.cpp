#include <bits/stdc++.h>
#include <queue>
#include <utility>
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
#define rep(i,s,e) for (int i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e2 + 5;
const int MAXM = 5e3 + 5;
struct Edge {
    int to, id;
};
struct EDge {
    int u, v;
    bool operator<(const EDge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    } 
};
vector<Edge> adj[MAXN];
EDge edges[MAXM];
vector<EDge> ans;
int n, m;
void check(int cid) {
    vector<bool> vis(n+1, 0);
    vis[1] = true;
    queue<int> q;
    q.push(1);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto [v, id] : adj[u]) {
            if (cid == id) continue;
            if (vis[v]) continue;
            vis[v] = true;
            q.push(v);
        }
    } 
    if (cnt < n) ans.push_back(edges[cid]);
}
void solve() {
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        edges[i] = {u, v}; 
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    rep(i, 1, m) check(i);
    sort(ans.begin(), ans.end());
    for (auto [u, v] : ans) {
        cout << u << " " << v << nl;
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
