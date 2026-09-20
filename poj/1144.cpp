//Thu Aug 13 03:46:08 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    while (std::cin >> n) {
        if (n == 0) break;
        std::vector<std::vector<int>> adj(n);
        std::string s;
        std::getline(std::cin, s);
        while (std::getline(std::cin, s)) {
            if (s.size() == 1 && s[0] == '0') break;
            int u = -1, v = -1;
            int cur = 0;
            for (char c : s) {
                if (c == ' ') {
                    if (u == -1) {
                        u = cur - 1;
                        cur = 0;
                    }
                    else {
                        v = cur - 1;
                        cur = 0;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                }else {
                    cur = 10 * cur + c - '0';
                }
            }
            if (cur > 0) {
                v = cur - 1;
                cur = 0;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        int tot = 0;
        std::vector<bool> cut(n);
        std::vector<int> dfn(n), low(n);
        auto dfs = [&](auto self, int u, int fa) -> void {
            dfn[u] = low[u] = ++tot;
            int child = 0;
            for (int v : adj[u]) if (v != fa){
                if (!dfn[v]) {
                    self(self, v, u);
                    child++;
                    low[u] = std::min(low[u], low[v]);
                    if (u != 0 && low[v] >= dfn[u]) cut[u] = true;
                }else {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (u == 0 && child >= 2) cut[u] = true;
        };
        dfs(dfs, 0, -1);
        std::cout << std::accumulate(cut.begin(), cut.end(), 0) << nl;
    }
}
