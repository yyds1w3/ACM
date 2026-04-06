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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> mp[i];
    }
    auto dfs = [&](auto self, int x, int y) -> void {
        if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || mp[x][y] != '0') {
            return;
        }
        mp[x][y] = '1';
        self(self, x - 1, y);
        self(self, x + 1, y);
        self(self, x, y - 1);
        self(self, x, y + 1);
    };
    for (int i = 0; i < n; ++i) {
        dfs(dfs, i, 0);
        dfs(dfs, i, m-1);
    }
    for (int i = 0; i < m; ++i) {
        dfs(dfs, 0, i);
        dfs(dfs, n - 1, i);
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += std::count(mp[i].begin(), mp[i].end(), '0');
    }
    std::cout << ans << nl;
}
