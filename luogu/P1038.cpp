//Wed Aug 12 08:41:58 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    i64 n, m;
    std::cin >> n >> m;
    std::vector<i64> C(n), U(n);
    for (i64 i = 0; i < n; ++i) {
        std::cin >> C[i] >> U[i];
    }
    std::vector<std::vector<std::pair<i64, i64>>> adj(n);
    std::vector<i64> in(n);
    for (i64 i = 0; i < m; ++i) {
        i64 u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        in[v]++;
    }
    std::queue<i64> q;
    std::vector<i64> id;
    for (i64 i = 0; i < n; ++i) {
        if (in[i] == 0) q.push(i);
        if (adj[i].empty()) id.push_back(i);
    }
    while (!q.empty()) {
        i64 u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            in[v]--;
            if (C[u] > 0) C[v] += w * C[u];
            if (in[v] == 0) {
                C[v] -= U[v];
                q.push(v);
            }
        }
    }
    bool ok = false;
    for (i64 i : id) {
        if (C[i] > 0) {
            ok = true;
            break;
        }
    }
    if (ok) {
        for (i64 i : id) {
            if (C[i] > 0) std::cout << i + 1 << " " << C[i] << nl;
        }
    }else {
        std::cout << "NULL" << nl;
    }
}
