//Sat Aug 22 02:28:14 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::set<int>> adj(n);
    std::vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        v--;
        adj[i].insert(v);
        adj[v].insert(i);
    }
    std::vector<int> cmp;
    auto dfs = [&](auto self, int u) -> void {
        vis[u] = true;
        cmp.push_back(u);
        for (int v : adj[u]) {
            if (!vis[v]) self(self, v);
        }
    };
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cmp.clear();
            dfs(dfs, i);
            bool f = true;
            for (int c : cmp) f &= adj[c].size() == 2;
            if (f) c1++;
            else c2++;
        }
    }
    int mn = c1 + (c2 > 0 ? 1 : 0);
    int mx = c1 + (c2 > 0 ? c2 : 0);
    std::cout << mn << " " << mx << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
