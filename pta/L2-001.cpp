//Thu Apr 16 04:16:14 PM CST 2026
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
    int to, w;
};
struct State {
    int u, d;
    bool operator<(const State& other) const {return d > other.d;} 
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m, s, d;
    std::cin >> n >> m >> s >> d;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<Edge>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    std::vector<int> dist(n, 1e9);
    std::vector<int> cnt(n, 0);
    std::vector<int> mxPeople(n, 0);
    std::vector<int> pre(n, -1);
    dist[s] = 0;
    cnt[s] = 1;
    mxPeople[s] = a[s];

    std::priority_queue<State> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                mxPeople[v] = mxPeople[u] + a[v];
                pre[v] = u;
                pq.push({v, dist[v]});
            }else if (dist[u] + w == dist[v]) {
                cnt[v] += cnt[u];
                if (mxPeople[u] + a[v] > mxPeople[v]) {
                    mxPeople[v] = mxPeople[u] + a[v];
                    pre[v] = u;
                }
            }
        }
    }
    std::cout << cnt[d] << " " << mxPeople[d] << nl;
    std::vector<int> path;
    for (int cur = d; cur != -1; cur = pre[cur]) {
        path.push_back(cur);
    }
    std::reverse(path.begin(), path.end());
    for (int i = 0, sz = path.size(); i < sz; ++i) {
        std::cout << path[i] << " \n"[i == sz - 1];
    }


}
