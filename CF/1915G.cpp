//Sun Aug 30 07:32:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}
const int N = 1000;
const int S = 1000;
const i64 INF = 2e18;
i64 dist[N][S + 1];
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::vector<i64> s(n);
    for (int i = 0; i < n; ++i) std::cin >> s[i];

    // d, u, s
    std::priority_queue<std::array<i64, 3>, std::vector<std::array<i64, 3>>, std::greater<std::array<i64, 3>>> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= S; ++j) {
            dist[i][j] = INF;
        }
    }
    dist[0][s[0]] = 0;
    pq.push({0, 0, s[0]});
    while (!pq.empty()) {
        auto [d, u, ns] = pq.top();
        pq.pop();
        if (d > dist[u][ns]) continue;
        for (auto [v, w] : adj[u]) {
            i64 nns = std::min(ns, s[v]);
            if (dist[v][nns] > dist[u][ns] + w * ns) {
                dist[v][nns] = dist[u][ns] + w * ns;
                pq.push({dist[v][nns], v, nns});
            }
        }
    }
    i64 ans = INF;
    for (int i = 0; i <= S; ++i) {
        ans = std::min(ans, dist[n-1][i]);
    }
    std::cout << ans << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
