//Thu Apr 23 01:07:21 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int INF = 1e9;
struct Edge {
    int v, limit, w;
};
struct Point {
    int u;
    int speed;
    double tim;
    bool operator<(const Point& other) const {
        return tim > other.tim;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector<std::vector<Edge>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, limit, w;
        std::cin >> u >> v >> limit >> w;
        adj[u].push_back({v, limit, w});
    }
    // dist[u][speed] = tim;
    std::vector<std::vector<double>> dist(n, std::vector<double>(501, INF));
    // pre[u][speed] = {u, speed};
    std::vector<std::vector<std::pair<int, int>>> pre(n, std::vector<std::pair<int, int>>(501, {-1, -1}));
    std::priority_queue<Point> pq;
    dist[0][70] = 0;
    pq.push({0, 70, 0});
    while (!pq.empty()) {
        auto [u, speed, tim] = pq.top();
        pq.pop();
        if (tim > dist[u][speed]) continue;
        for (auto [v, limit, w] : adj[u]) {
            if (limit == 0) limit = speed;
            double cost = 1.0 * w / limit;
            if (dist[u][speed] + cost < dist[v][limit]) {
                dist[v][limit] = dist[u][speed] + cost;
                pre[v][limit] = {u, speed};
                pq.push({v, limit, dist[v][limit]});
            }
        }
    }
    double mn = INF;
    int finalV = -1;
    for (int speed = 1; speed <= 500; ++speed) {
        if (dist[d][speed] < mn) {
            mn = dist[d][speed];
            finalV = speed;
        }
    }
    std::vector<int> path;
    int curU = d;
    int curSpeed = finalV;
    while (curU != -1) {
        path.push_back(curU);
        auto p = pre[curU][curSpeed];
        curU = p.first;
        curSpeed = p.second;
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        std::cout << path[i] << " \n"[i == 0];
    }
}
