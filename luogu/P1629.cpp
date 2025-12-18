#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
struct Edge{
    int v, w;
    bool operator<(const Edge &other) const {return w > other.w;}
};
const int MAXN = 1e3 + 1;
int n, m, u, v, w;
vector<Edge> adj[MAXN];
vector<Edge> radj[MAXN];
int dist[MAXN];
void dijsktra(int u, vector<Edge> adj[]){
    priority_queue<Edge> pq;
    memset(dist, 0x3f, sizeof(dist));
    dist[u] = 0;
    pq.push({u, 0});
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        if (curr.w > dist[curr.v]) continue;
        for (auto edge : adj[curr.v]){
             if (dist[curr.v] + edge.w < dist[edge.v]){
                dist[edge.v] = dist[u] + edge.w;
                pq.push({edge.v, edge.w});
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
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
    while (tt--) {
        solve();
    }
    return 0;
}
