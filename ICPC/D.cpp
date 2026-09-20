//Thu Sep  3 02:28:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, std::pair<int, i64>& rhs) {
    return os << "[" << rhs.first << "," << rhs.second << "]";
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<std::pair<int, i64>> a;
    std::vector<int> dfn(n);
    auto dfs = [&](auto self, int u) -> std::pair<int, i64> {
        int point = 1;
        i64 edges = 0;
        for (int v : adj[u]) {
            if (!dfn[v]) {
                edges++;
                dfn[v] = dfn[u] + 1;
                auto [p, e] = self(self, v);
                point += p;
                edges += e;
            }else if (dfn[u] < dfn[v]) edges++;
        }
        return {point, edges};
    };
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            dfn[i] = 1;
            a.push_back(dfs(dfs, i));
        }
    }
    i64 ans = 0;
    bool f = true;
    for (auto [p, e] : a) {
        if (e < 1LL * p * (p - 1) / 2) {
            ans += 1LL * p * (p - 1) / 2 - e;
            f = false;
        }
    }
    // debugv(a, a.size());
    if (!f) {
        std::cout << ans << nl;
    }else {
        std::sort(a.begin(), a.end());
        int p1 = a[0].first;
        int p2 = a[1].first;
        int p3 = p1 + p2;
        std::cout << 1LL*p3*(p3-1)/2 - 1LL*p1*(p1-1)/2 - 1LL*p2*(p2-1)/2 << nl;;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
