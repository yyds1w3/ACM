//Mon Aug 17 08:21:31 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int m;
    std::cin >> m;
    std::vector<std::vector<int>> g(500, std::vector<int>(500));
    std::vector<int> deg(500);
    int s = 500;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u][v]++;
        g[v][u]++;
        deg[u]++;
        deg[v]++;
    }
    int odd = 0;
    for (int i = 0; i < 500; ++i) {
        if (deg[i] & 1) odd++;
    }
    if (odd > 0) {
        for (int i = 0; i < 500; ++i) {
            if (deg[i] & 1) {s = i; break;}
        }
    }else {
        for (int i = 0; i < 500; ++i) {
            if (deg[i] > 0) {s = i; break;}
        }
    }
        
    std::vector<std::string> ans;
    auto dfs = [&](auto self, int u) -> void {
        for (int v = 0; v < 500; ++v) {
            while (g[u][v]) {
                g[u][v]--;
                g[v][u]--;
                self(self, v);
            }
        }
        ans.push_back(std::to_string(u + 1));
    };
    dfs(dfs, s);
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); ++i) {
        std::cout << ans[i] << nl;
    }
}
