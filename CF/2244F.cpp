//Thu Aug 27 12:49:57 PM CST 2026
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
std::ostream& operator<<(std::ostream& os, std::pair<int, int>& rhs) {
    return os << "[" <<rhs.first << "," << rhs.second << "]";
}
const int INF = 1e9;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int u;
        std::cin >> u;
        u--;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<std::pair<int, int>> dp(n);

    bool ok = true;
    auto dfs = [&](auto self, int u, int fa) -> void {
        if (a[u] != 0) {
            dp[u] = {a[u], a[u]};
            return;
        };

        std::vector<int> son;
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            son.push_back(v);
        }

        auto [l, r] = dp[son[0]];
        int i = 1, j = son.size() - 1;
        while (i <= j) {
            if (r < dp[son[i]].first) {
                r = dp[son[i]].second;
                i++;
            }else break;
        }
        while (j >= i) {
            if (l > dp[son[j]].second) {
                l = dp[son[j]].first;
                j--;
            }else break;
        }
        if (i <= j) ok = false;
        else dp[u] = {l, r};
    };
    dfs(dfs, 0, -1);
    if (ok) std::cout << "YES" << nl;
    else std::cout << "NO" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
