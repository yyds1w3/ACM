//Fri Aug 21 08:03:59 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
const int MOD = 1e9 + 7;
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        if (!w) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    std::vector<bool> vis(n);
    std::vector<int> cmp;
    auto dfs = [&](auto self, int u) -> void {
        vis[u] = true;
        cmp.push_back(u);
        for (int v : adj[u]) {
            if (!vis[v]) {
                self(self, v);
            }
        }
    };
    i64 ans = qpow(n, k);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cmp.clear();
            dfs(dfs, i);
            ans = (ans + MOD - qpow((i64)cmp.size(), k)) % MOD;
        }
    }
    std::cout << ans << nl;
}
