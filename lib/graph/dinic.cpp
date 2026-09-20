#include <bits/stdc++.h>
using i64 = long long;
const int N = 200;
const i64 INF = 2e18;
struct Edge {
    int v, rev;
    i64 c, flow;
};
int n, m, s, t;
std::vector<std::vector<Edge>> adj(N);
std::vector<int> dist(N), cur(N);
void init(int n) {
    for (int i = 0; i < n; ++i) adj[i].clear();
    dist.assign(n, -1);
    cur.assign(n, 0);
}
void addEdge(int u, int v, i64 c) {
    adj[u].push_back({v, (int)adj[v].size(), c, 0});
    adj[v].push_back({u, (int)adj[u].size()-1, 0, 0});
}
bool bfs(int s, int t) {
    std::fill(dist.begin(), dist.begin() + n, -1);
    dist[s] = 0;
    std::vector<int> q(n);
    int head = 0, top = -1;
    q[++top] = s;
    while (head <= top) {
        int u = q[head++];
        for (auto [v, rev, c, flow] : adj[u]) {
            if (dist[v] == -1 && c - flow > 0) {
                dist[v] = dist[u] + 1;
                q[++top] = v;
            }
        }
    }
    return dist[t] != -1;
}
i64 dfs(int u, int t, i64 flow) {
    if (u == t || flow == 0) return flow;
    i64 pushed = 0;
    for (int& i = cur[u]; i < (int)adj[u].size(); ++i) {
        auto& [v, rev, c, eflow] = adj[u][i];
        if (dist[v] == dist[u] + 1 && c - eflow > 0) {
            i64 f = dfs(v, t, std::min(flow - pushed, c - eflow));
            if (f == 0) continue;
            eflow += f;
            adj[v][rev].flow -= f;
            pushed += f;
            if (pushed == flow) break;
        }
    }
    return pushed;
}
i64 work(int s, int t) {
    i64 ans = 0;
    while (bfs(s, t)) {
        std::fill(cur.begin(), cur.begin() + n, 0);
        ans += dfs(s, t, INF);
    }
    return ans;
}
