//Wed Aug 12 07:54:15 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> in(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        in[u]++;
    }
    std::priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) q.push(i);
    }
    std::vector<int> ans;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        ans.push_back(u);
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    if (ans.size() < n) std::cout << "Impossible!" << nl;
    else {
        for (int i = n - 1; i >= 0; --i) std::cout << ans[i] + 1 << " ";
        std::cout << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
