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
    int n;
    std::cin >> n;
    std::vector arr(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> arr[i][j];
        }
    }
    auto dfs = [&](auto self, int sx, int sy) -> void {
        if (sx < 0 || sx > n - 1 || sy < 0 || sy > n-1 || arr[sx][sy] != 0) {
            return;
        }
        arr[sx][sy] = 3;
        self(self, sx - 1, sy);
        self(self, sx + 1, sy);
        self(self, sx, sy - 1);
        self(self, sx, sy + 1);
    };
    for (int i = 0; i < n; ++i) {
        dfs(dfs, i, 0);
        dfs(dfs, i, n-1);
        dfs(dfs, 0, i);
        dfs(dfs, n-1, i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 3) std::cout << 0 << " ";
            else if (arr[i][j] == 1) std::cout << 1 << " ";
            else if (arr[i][j] == 0) std::cout << 2 << " ";
        }
        std::cout << nl;
    }
}
