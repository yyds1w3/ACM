//Sat Aug 22 02:45:32 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u == v) ok = false;
    }
    if (!ok) {
        std::cout << "NO" << nl;
        return;
    }
    std::vector<int> col(n);
    std::vector<bool> vis(n);
    auto bit = [](int x, int b) -> int {
        return (x >> b) & 1;
    };
    auto dfs = [&](auto self, int u, int fa) -> void {
        bool f = true;
        vis[u] = true;
        for (int v : adj[u]) {
            if (v == fa && f) {
                f = false;
                continue;
            }
            for (int i = 0; i < 2; ++i) {
                if (!bit(col[u], i) && !bit(col[v], i)) {
                    col[u] |= (1 << i);
                    col[v] |= (1 << i);
                    break;
                }
            }
            if (!vis[v]) self(self, v, u);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(dfs, i, -1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] != 3) {
            std::cout << "NO" << nl;
            return;
        }
    }
    std::cout << "YES" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
