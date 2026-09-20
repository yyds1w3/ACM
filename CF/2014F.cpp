//Sat Aug 29 02:32:21 PM CST 2026
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
    i64 u, val;
    bool operator<(const st& other) const {
        return val < other.val;
    }
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n, c;
    std::cin >> n >> c;
    std::vector<i64> a(n);
    std::vector<std::vector<int>> adj(n);

    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<std::vector<i64>> dp(n, std::vector<i64>(2));
    auto dfs = [&](auto self, int u, int p) -> void {
        dp[u][0] = 0;
        dp[u][1] = a[u];
        for (int v : adj[u]) if (v != p) {
            self(self, v, u);
            dp[u][0] += std::max(dp[v][0], dp[v][1]);
            dp[u][1] += std::max(dp[v][0], dp[v][1] - 2*c);
        }
    };
    dfs(dfs, 0, -1);
    std::cout << std::max(dp[0][0], dp[0][1]) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
