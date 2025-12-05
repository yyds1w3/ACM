#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 100005;

struct Edge {
    int v;
    ll w;
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};

int n, m, k;
vector<Edge> adj[N];
ll dist[N];

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    
    priority_queue<Edge> pq;
    pq.push({s, 0});
    dist[s] = 0;

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();
        int u = curr.v;
        if (curr.w > dist[u]) continue;

        for (Edge e : adj[u]) {
            if (dist[u] + e.w < dist[e.v]) {
                dist[e.v] = dist[u] + e.w;
                pq.push({e.v, dist[e.v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; ++i) { 
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, (ll)w});
        adj[v].push_back({u, (ll)w});
    }

    for (int i = 1; i <= k; ++i) { 
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0}); // 权值为 0
        adj[v].push_back({u, 0});
    }

    dijkstra(1);
    
    cout << dist[n] << endl;
    return 0;
}