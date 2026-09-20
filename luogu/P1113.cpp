//Wed Aug 12 06:50:14 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), in(n + 1);
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int u, v;
        std::cin >> u >> a[i];
        while (std::cin >> v) {
            if (v == 0) break;
            in[u]++;
            adj[v].push_back(u);
        }
    }
    std::vector<int> q(n);
    int head = 0, tail = -1;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q[++tail] = i;
            dp[i] = a[i];
        }
    }
    while (head <= tail) {
        int u = q[head++];
        for (int v : adj[u]) {
            dp[v] = std::max(dp[v], dp[u] + a[v]);
            in[v]--;
            if (in[v] == 0) q[++tail] = v;
        }
    }
    std::cout << *std::max_element(dp.begin() + 1, dp.end()) << nl;

}
