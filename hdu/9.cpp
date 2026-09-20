//Thu Aug 20 07:46:19 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl; 
#define debugv(v, sz) std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;
#define debugvv(v, sz1, sz2) std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}
using i64 = long long;
using i128 = __int128;
const int MOD = 998244353;
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
i64 inv(i64 x) {
    return qpow(x, MOD - 2);
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<bool> vis(n);
    std::vector<int> dfn(n);
    int tlen = 0;
    for (int i = 0; i < n; ++i) {
        int len = 0;
        auto dfs = [&](auto self, int u, int p) -> void {
            vis[u] = true;
            dfn[u] = (p == -1 ? 1 : dfn[p] + 1);
            bool f = false;
            for (int v : adj[u]) {
                if (v == p && !f) {
                    f = true;
                }else if (vis[v]) {
                    if(dfn[u] > dfn[v]) len = dfn[u] - dfn[v] + 1;
                }else {
                    self(self, v, u);
                }
            }
        };
        if (!vis[i]) dfs(dfs, i, - 1);
        tlen += len;
    }
    std::cout << ((n - tlen) + tlen * inv(2) % MOD) % MOD << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
