//Sun Aug 16 02:06:42 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(2 * n);
    for (int i = 0; i < m; ++i) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        bool f1 = s1[0] == 'm';
        bool f2 = s2[0] == 'm'; 
        int u = std::stoi(s1.substr(1)) - 1;
        int v = std::stoi(s2.substr(1)) - 1;
        adj[2*u+!f1].push_back(2*v+f2);
        adj[2*v+!f2].push_back(2*u+f1);
    }
    int tot = 0, cnt = 0;
    std::vector<int> dfn(2*n), low(2*n), stk, id(2*n);
    auto dfs = [&](auto self, int u) -> void {
        dfn[u] = low[u] = ++tot;
        stk.push_back(u);
        for (int v : adj[u]) {
            if (!dfn[v]) {
                self(self, v);
                low[u] = std::min(low[u], low[v]);
            }else if (!id[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            cnt++;
            while (true) {
                int x = stk.back();
                stk.pop_back();
                id[x] = cnt;
                if (x == u) break;
            }
        }
    };
    for (int i = 0; i < 2 * n; ++i) {
        if (!dfn[i]) dfs(dfs, i);
    }
    for (int i = 0; i < n; ++i) {
        if (id[2*i] == id[2*i+1]) {
            std::cout << "BAD" << nl;
            return;
        }
    }
    std::cout << "GOOD" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
