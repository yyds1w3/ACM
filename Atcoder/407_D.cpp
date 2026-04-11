#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int h, w;
    std::cin >> h >> w;
    std::vector<i64> a(h*w);
    for (int i = 0; i < h * w; ++i) {
        std::cin >> a[i];
    }
    std::vector<bool> vis(h * w);
    i64 ans = 0;
    auto dfs = [&](auto self, int u, i64 cur) -> void {
        if (u == h * w) {
            ans = std::max(ans, cur);
            return;
        }
        if (vis[u] == true) {
            self(self, u + 1, cur);
        }else {
            self(self, u + 1, cur ^ a[u]);
            if (u % w != w - 1 && vis[u+1] == false) {
                vis[u + 1] = true; 
                self(self, u + 1, cur);
                vis[u + 1] = false;
            }
            if (u / w != h - 1) {
                vis[u + w] = true;
                self(self, u + 1, cur);
                vis[u + w] = false;
            }
        }
    };
    dfs(dfs, 0, 0);
    std::cout << ans << nl;
}
