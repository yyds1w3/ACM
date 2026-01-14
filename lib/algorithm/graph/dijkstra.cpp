/**
 * Algorthim: Dijkstra (Priority Queue Optimized)
 * Verified: Luogu P4779
 * Complexity: O(E log V)
 * Author: Qingw
 */
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
// =======================start===========================
ll dist[MAXN];
struct Edge {
    int v;
    ll w;
    bool operator<(const Edge& other) const {return w > other.w;}
};
vector<Edge> adj[MAXN];
void dji(int s) {
    fill(dist, dist + MAXN, LINF);
    dist[s] = 0;
    priority_queue<Edge> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& e : adj[u]) {
            int v = e.v;
            ll w = e.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
}
