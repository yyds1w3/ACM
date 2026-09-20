//Mon Aug 24 11:38:45 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> sz(n);
    i64 tot = 0;
    auto dfs = [&](auto self, int u, int fa) -> void {
        sz[u] = 1;
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            sz[u] += sz[v];
        }
        if ((i64)std::sqrtl(a[u]) * (i64)std::sqrt(val) == val) {
            i64 sum = n - sz[u];
            i64 pai = 0;
            i64 tri = 0;
            for (int v : adj[u]) if (v != fa) {
                tri += pai * sz[v];
                pai += sum * sz[v];
                sum += sz[v];
            }
            tot += pai + tri;
        }
    };
    dfs(dfs, 0, -1);
    std::cout << tot << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
