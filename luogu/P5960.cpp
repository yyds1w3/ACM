//Wed Apr 22 04:27:13 PM CST 2026
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

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[v].push_back({w, u});
    }
    std::vector<int> dist(n), cnt(n), inq(n);
    std::queue<int> q;
    auto spfa = [&]() -> bool {
        for (int i = 0; i < n; ++i) {
            q.push(i);
            inq[i] = 1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto [w, v] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n) return true;
                    if (!inq[v]) {
                        inq[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
        return false;
    };
    if (spfa()) {
        std::cout << "NO" << nl;
    }else {
        for (int i = 0; i < n; ++i) {
            std::cout << dist[i] << " ";
        }
    }
}
