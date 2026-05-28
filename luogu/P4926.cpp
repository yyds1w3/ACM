//Mon Apr 27 11:54:58 AM CST 2026
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

struct Edge {
    int type, u, v, k;
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, s, t;
    if (!(std::cin >> n >> s >> t)) return 0;
    std::vector<Edge> a(s);
    for (Edge &e : a) {
        std::cin >> e.type >> e.u >> e.v >> e.k;
        e.u--;
        e.v--;
    }
    std::vector<std::pair<int, double>> people(t);
    for (auto &p : people) {
        std::cin >> p.first >> p.second;
        p.first--;
    }
    auto check = [&](double T) -> bool {
        std::vector<std::vector<std::pair<int, double>>> adj(n + 1);
        for (auto [type, u, v, k] : a) {
            if (type == 1) {
                if (k - T > 0) {
                    adj[v].push_back({u, std::log2(k - T)});
                }
            } else {
                adj[v].push_back({u, -std::log2(k + T)});
            }
        }
        
        int super_node = n;
        for (auto [u, x] : people) {
            adj[super_node].push_back({u, std::log2(x)});
            adj[u].push_back({super_node, -std::log2(x)});
        }
        std::vector<double> dist(n + 1, 0.0);
        std::vector<int> cnt(n + 1, 0), inq(n + 1);
        std::queue<int> q;
        for (int i = 0; i <= n; ++i) {
            q.push(i);
            inq[i] = 1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto [v, w] : adj[u]) {
                if (dist[v] < dist[u] + w) {
                    dist[v] = dist[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] > n) return true; 
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = 1;
                    }
                }
            }
        }
        return false;
    };
    if (!check(0)) {
        std::cout << -1 << nl;
        return 0;
    }
    double l = 0, r = 11.0; 
    for (int i = 0; i < 60; ++i) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout << std::setprecision(5) << std::fixed << l << nl;
    return 0;
}
