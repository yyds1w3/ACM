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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> s(h);
    for (int i = 0; i < h; ++i) {
        std::cin >> s[i]; 
    }
    auto dfs = [&](auto self, int x, int y) -> void{
        if (s[x][y] == '.') {
            s[x][y] = '#';
            for (int i = 0; i < 4; ++i) {
                int ex = x + dx[i];
                int ey = y + dy[i];
                if (ex < 0 || ex >= h || ey < 0 || ey >= w) continue;
                self(self, ex, ey);
            }
        }
    };
    for (int i = 0; i < h; ++i) {
        if (s[i][0] == '.') dfs(dfs, i, 0);
        if (s[i][w-1] == '.') dfs(dfs, i, w-1);
    }
    for (int i = 0; i < w; ++i) {
        if (s[0][i] == '.') dfs(dfs, 0, i);
        if (s[h-1][i] == '.') dfs(dfs, h-1, i);
    } 
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '.') {
                dfs(dfs, i, j);
                ans += 1;
            }
        }
    }
    std::cout << ans << nl;
}
