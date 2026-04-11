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
    #endif
    int n;
    std::cin >> n;
    std::vector<int> in(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        int u;
        while (std::cin >> u) {
            if (u == 0) break;
            u--;
            in[u]++;
            adj[i].push_back(u);
        }
    }
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u + 1 << " ";
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
}
