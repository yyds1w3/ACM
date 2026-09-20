//Mon Aug 17 07:35:19 PM CST 2026
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
    std::vector<std::vector<int>> g(200, std::vector<int>(200));
    std::vector<int> deg(200);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        int u = s[0];
        int v = s[1];
        g[u][v]++;
        g[v][u]++;
        deg[u]++;
        deg[v]++;
    }
    int odd = 0;
    int s = -1;
    for (int i = 0; i < 200; ++i) {
        if (deg[i] & 1) {
            odd++;
            if (s == -1) s = i;
        }
    }
    if (odd != 0 && odd != 2) {
        std::cout << "No Solution" << nl;
        return 0;
    }
    std::string ans;
    auto dfs = [&](auto self, int u) -> void {
        for (int v = 0; v < 200; ++v) {
            while (g[u][v]) {
                g[u][v]--;
                g[v][u]--;
                self(self, v);
            }
        }
        ans += char(u);
    };
    if (s != -1) {
        dfs(dfs, s);
    }else {
        for (int i = 0; i < 200; ++i) {
            if (deg[i] > 0) {
                s = i;
                break;
            }
        }
        dfs(dfs, s);
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << nl;
}
