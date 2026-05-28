//Sat May  9 04:07:46 PM CST 2026
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> in(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        u--, v--;
        if (x > y) {
            adj[v].push_back(u);
            in[u]++;
        }else {
            adj[u].push_back(v);
            in[v]++;
        }
    }
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    std::vector<int> p(n);
    int val = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        p[u] = val++;
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int v : p) {
        std::cout << v << " ";
    }
    std::cout << nl;
}

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
        solve();
    }
}
