//Sun Aug 23 09:32:15 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
const i64 INF = 1e18;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    std::vector<std::vector<std::pair<int, i64>>> adj(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    auto check = [&](i64 x) -> bool {
        std::vector<i64> dp(n, -1);
        dp[0] = std::min(x, a[0]);
        for (int i = 0; i < n; ++i) {
            for (auto [v, w] : adj[i]) {
                if (dp[i] >= w) {
                    dp[v] = std::min(x, std::max(dp[v], dp[i] + a[v]));
                }
            }
        }
        return dp[n-1] != -1;
    };
    i64 l = 0, r = 1e9 + 1;
    while (l < r) {
        i64 mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }else l = mid + 1;
    }
    if (l == 1e9 + 1) {
        std::cout << -1 << nl;
    }else {
        std::cout << l << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
