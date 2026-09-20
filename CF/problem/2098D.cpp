//Wed Jun 17 03:59:53 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int MOD = 1e9 + 7;
void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> adj(n * m);
    std::vector<int> x(k + 1), y(k + 1);
    std::vector<int> self_loop(n * m);
    std::vector<bool> given(n * m);
    auto getId = [&](int x, int y) -> int {
        return x * m + y;
    };
    bool f1 = true;
    for (int i = 0; i < k + 1; ++i) {
        std::cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        if (given[getId(x[i], y[i])] == false) {
            given[getId(x[i], y[i])] = true;
        }else {
            f1 = false;
        }
    }
    if (f1 == false) {
        std::cout << 0 << nl;
        return;
    }
    for (int i = 0; i < k; ++i) {
        int d = std::abs(x[i] - x[i + 1]) + std::abs(y[i] - y[i + 1]);
        if (d != 2) {
            std::cout << 0 << nl;
            return;
        }
        if (x[i] == x[i + 1]) {
            int u = getId(x[i], std::min(y[i] + 1, y[i + 1] + 1));
            self_loop[u]++;
        }else if (y[i] == y[i + 1]) {
            int u = getId(std::min(x[i] + 1, x[i + 1] + 1), y[i]);
            self_loop[u]++;
        }else {
            int u = getId(x[i], y[i + 1]);
            int v = getId(x[i + 1], y[i]);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    std::vector<bool> vis(n * m);
    int E, V, Loop;
    auto dfs = [&](auto self, int u) -> void {
        vis[u] = true;
        Loop += self_loop[u];
        V++;
        E += adj[u].size();
        for (int v : adj[u]) if (!vis[v]) {
            self(self, v);
        }
    };
    i64 ans = 1;
    for (int i = 0; i < n * m; ++i) {
        if (vis[i]) continue;
        if (adj[i].size() == 0 && self_loop[i] == 0) {
            vis[i] = true;
            continue;
        }
        E = 0, V = 0, Loop = 0;
        dfs(dfs, i);
        E = E / 2 + Loop;
        if (E == V - 1) {
            ans = (ans * V) % MOD;
        }else if (E == V) {
            if (Loop == 0) {
                ans = (ans * 2) % MOD;
            }else if (Loop == 1) {
                ans = (ans * 1) % MOD;
            }
        }else {
            std::cout << 0 << nl;
            return;
        }
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
