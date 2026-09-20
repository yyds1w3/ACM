//Thu Aug 20 08:44:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl; 
#define debugv(v, sz) std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;
#define debugvv(v, sz1, sz2) std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}
using i64 = long long;
using i128 = __int128;
const int N = 400;
const i64 INF = 2e18;
struct Edge {
    int v, rev;
    i64 c, flow;
};
int n, m, s, t;
std::vector<std::vector<Edge>> adj(2*N+2);
std::vector<int> dist(2*N+2), cur(2*N+2);
void init(int n) {
    for (int i = 0; i < 2*n+2; ++i) adj[i].clear();
    dist.assign(2*n+2, -1);
    cur.assign(2*n+2, 0);
}
void addEdge(int u, int v, i64 c) {
    adj[u].push_back({v, (int)adj[v].size(), c, 0});
    adj[v].push_back({u, (int)adj[u].size()-1, 0, 0});
}
bool bfs(int s, int t) {
    std::fill(dist.begin(), dist.begin() + 2*n+2, -1);
    dist[s] = 0;
    std::vector<int> q(2*n+2);
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
        std::fill(cur.begin(), cur.begin() + 2*n+2, 0);
        ans += dfs(s, t, INF);
    }
    return ans;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int r, c, d;
    std::cin >> r >> c >> d;
    n = r * c;
    s = 2 * n;
    t = 2 * n + 1;
    std::vector<std::string> a(r), b(r);
    for (int i = 0; i < r; ++i) std::cin >> a[i];
    for (int i = 0; i < r; ++i) std::cin >> b[i];
    auto getid = [&](int i, int j) -> int {
        return i * c + j;
    };
    int tot = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == '0') continue;
            int u = getid(i, j);
            addEdge(2*u,2*u+1,a[i][j]-'0');
            if (b[i][j] == 'L') {
                addEdge(s, 2*u, 1);
                tot++;
            }
            if (i < d || i + d >= r || j < d || j + d >= c) addEdge(2*u+1, t, INF);
            for (int ni = 0; ni < r; ++ni) {
                for (int nj = 0; nj < c; ++nj) {
                    if ((i == ni && j == nj) || a[ni][nj] == '0') continue;
                    int v = getid(ni, nj);
                    if ((i - ni) * (i - ni) + (j - nj) * (j - nj) <= d * d) {
                        addEdge(2*u+1, 2*v, INF);
                    }
                }
            }
        }
    }
    std::cout << tot - work(s, t) << nl;

}
