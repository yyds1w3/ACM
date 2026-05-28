//Fri Apr 17 03:28:37 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    
    std::vector<std::vector<int>> adj(n);
    std::vector<bool> notRoot(n);
    for (int i = 0; i < n - 1; ++i) {
        int l, k;
        std::cin >> l >> k;
        l--, k--;
        adj[k].push_back(l);
        notRoot[l] = true;
    }
    
    std::vector<std::vector<int>> dp(n, std::vector<int>(2));
    auto dfs = [&](auto self, int u) -> void {
        dp[u][1] = a[u];
        for (int v : adj[u]) {
            self(self, v);
            dp[u][0] += std::max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };
    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (notRoot[i] == false) {
            root = i;
        }
    }
    dfs(dfs, root);
    std::cout << std::max(dp[root][0], dp[root][1]) << nl;
}
