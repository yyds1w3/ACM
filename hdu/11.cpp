//Tue Aug 18 12:05:34 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
i64 MOD = 998244353;
const int N = 5200;
int n;
std::vector<std::vector<int>> adj(N);
int fa[N][20];
int dep[N];
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
i64 inv(i64 a) {
    return qpow(a, MOD - 2);
}
void init(int n) {
    for (int i = 0; i < n; ++i) adj[i].clear();
    memset(fa, 0, sizeof(fa));
    memset(dep, 0, sizeof(dep));
}
void dfs(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        for (int i = 1; i <= 19; ++i) {
            fa[v][i] = fa[fa[v][i-1]][i-1];
        }
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        std::swap(u, v);
    }
    for (int i = 19; i >= 0; --i) {
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
void solve() {
    std::cin >> n;
    init(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    std::vector<int> leafs;
    for (int i = 1; i < n; ++i) {
        if (adj[i].size() == 1) {
            leafs.push_back(i);
        }
    }
    int m = leafs.size();
    i64 ans1 = 0, ans2 = 1;
    for (int i = 0; i < m; ++i) {
        i64 ans3 = 1, ans4 = 1;
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            int u = leafs[i];
            int v = leafs[j];
            int ff = lca(u, v);
            int d1 = dep[u] - dep[ff];
            int d2 = dep[v] - dep[ff];
            if (ans3 * (d1 + d2) > ans4 * d2) {
                ans3 = d2;
                ans4 = d2 + d1;
            }
        }
        if (ans1 * ans4 < ans2 * ans3) {
            ans1 = ans3;
            ans2 = ans4;
        }
    }
    std::cout << ans1 * inv(ans2) % MOD << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
