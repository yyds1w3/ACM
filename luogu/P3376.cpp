//Thu Aug 20 02:38:34 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl; 
#define debugv(v, sz) std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;
#define debugvv(v, sz1, sz2) std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}
using i64 = long long;
using i128 = __int128;
const int N = 200;
struct Edge {
    int v, rev;
    i64 c, flow;
};
int n, m, s, t;
std::vector<std::vector<Edge>> adj(N);
std::vector<int> dist(N), cur(N);
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
        ans += dfs(s, t, 1e18);
    }
    return ans;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::cin >> n >> m >> s >> t;
    s--, t--;
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--, v--;
        addEdge(u, v, w);
    }
    std::cout << work(s, t) << nl;
}
