//Sun May  3 12:31:30 PM CST 2026
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

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int w;
        std::cin >> w;
        std::vector<std::string> s(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> s[i];
        }
        int tot = n * w;
        std::vector<std::vector<int>> g(tot);
        std::vector<int> in(tot);
        for (int u = 0; u < n; ++u) {
            for (int d = 0; d < w; ++d) {
                if (s[u][d] == 'x') {
                    continue;
                }else {
                    int id = u * w + d;
                    if (s[u][(d + 1) % w] == 'o') {
                        int nid = u * w + (d + 1) % w; 
                        g[id].push_back(nid);
                        in[nid]++;
                    }
                    for (int v : adj[u]) {
                        if (s[v][(d + 1) % w] == 'o') {
                            int nid = v * w + (d + 1) % w;
                            g[id].push_back(nid);
                            in[nid]++;
                        }
                    }
                }
            }
        }
        std::queue<int> q;
        for (int i = 0; i < tot; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for (int v : g[u]) {
                in[v]--;
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (cnt == tot) {
            std::cout << "No" << nl;
        }else {
            std::cout << "Yes" << nl;
        }
    }
}
