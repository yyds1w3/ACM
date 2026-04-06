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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    std::vector<std::vector<int>> comb(15, std::vector<int>(15));
    comb[0][0] = 1;
    for (int i = 1; i < 15; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
    int n, sum;
    std::cin >> n >> sum;
    std::vector<int> path(n);
    std::vector<bool> vis(n + 1);
    bool found = false;
    auto dfs = [&](auto self, int idx, int cur) -> void {
        if (idx == n) {
            if (cur == sum) {
                found = true;
                for (int num : path) {
                    std::cout << num << " ";
                }
                std::cout << nl;
                return;
            }
        }
        if (cur > sum) return;
        if (found) return;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                path[idx] = i;
                self(self, idx + 1, cur + i * comb[n-1][idx]);
                vis[i] = false;
            }
        }
    };
    dfs(dfs, 0, 0);
}
