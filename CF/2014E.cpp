//Mon Aug 24 06:53:24 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
const i64 INF = 1e18;
struct st {
    int u;
    i64 d;
    int hor;
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n, m, h;
    std::cin >> n >> m >> h;
    std::vector<bool> horse(n);
    for (int i = 0; i < h; ++i) {
        int x;
        std::cin >> x;
        x--;
        horse[x] = true;
    }
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    std::vector<std::vector<i64>> dist1(n, std::vector<i64>(2, INF)), dist2(n, std::vector<i64>(2, INF));
    auto cmp = [](const st& lhs, const st& rhs) -> bool {
        return lhs.d > rhs.d;
    };
    std::priority_queue<st, std::vector<st>, decltype(cmp)> pq1(cmp);
    std::priority_queue<st, std::vector<st>, decltype(cmp)> pq2(cmp);
    dist1[0][0] = 0, dist2[n-1][0] = 0;
    if (horse[0]) dist1[0][1] = 0;
    if (horse[n-1]) dist2[n-1][1] = 0;
    pq1.push({0, 0, 0}), pq2.push({n-1, 0, 0});
    if (horse[0]) pq1.push({0, 0, 1});
    if (horse[n-1]) pq2.push({n-1,0,1});
    while (!pq1.empty()) {
        auto [u, d, hor] = pq1.top();
        pq1.pop();
        if (d > dist1[u][hor]) continue;
        for (auto [v, w] : adj[u]) {
            if (hor) {
                if (d + w / 2 < dist1[v][hor|horse[v]]) {
                    dist1[v][hor|horse[v]] = d + w / 2;
                    pq1.push({v, d + w / 2, hor|horse[v]});
                }
            }else {
                if (d + w < dist1[v][hor|horse[v]]) {
                    dist1[v][hor|horse[v]] = d + w;
                    pq1.push({v, d + w, hor|horse[v]});
                }
            }
        }
    }
    while (!pq2.empty()) {
        auto [u, d, hor] = pq2.top();
        pq2.pop();
        if (d > dist2[u][hor]) continue;
        for (auto [v, w] : adj[u]) {
            if (hor) {
                if (d + w / 2 < dist2[v][hor|horse[v]]) {
                    dist2[v][hor|horse[v]] = d + w / 2;
                    pq2.push({v, d + w / 2, hor|horse[v]});
                }
            }else {
                if (d + w < dist2[v][hor|horse[v]]) {
                    dist2[v][hor|horse[v]] = d + w;
                    pq2.push({v, d + w, hor|horse[v]});
                }
            }
        }
    }
    // debugvv(dist1, n, 2);
    // debugvv(dist2, n, 2);
    i64 ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = std::min(ans, std::max(std::min(dist1[i][0], dist1[i][1]), std::min(dist2[i][0], dist2[i][1])));
    }
    if (ans == INF) {
        std::cout << -1 << nl;
    }else {
        std::cout << ans << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
