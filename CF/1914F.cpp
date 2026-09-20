//Tue Aug 25 12:27:53 PM CST 2026
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
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int u;
        std::cin >> u;
        u--;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    std::vector<int> dp(n), sz(n);
    auto dfs = [&](auto self, int u, int p) -> void {
        sz[u] = 1;
        for (int v : adj[u]) if (v != p) {
            self(self, v, u);
            sz[u] += sz[v];
        }
        int res = (sz[u] - 1) % 2;
        for (int v : adj[u]) if (v != p) {
            res = std::max(res, dp[v] - (sz[u] - 1 - sz[v]));
        }
        dp[u] = res + 1;
    };
    dfs(dfs, 0, -1);
    std::cout << (n - dp[0]) / 2 << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
