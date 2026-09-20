//Sat Aug  8 02:54:59 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
i64 dp[31][31];
int root[30][30];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> dp[i][i];
        root[i][i] = i;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            for (int k = i; k <= j; ++k) {
                if (dp[i][j] < (i > k - 1 ? 1 : dp[i][k-1]) * ((k + 1 > j) ? 1 : dp[k+1][j]) + dp[k][k]) {
                    dp[i][j] = (i > k - 1 ? 1 : dp[i][k-1]) * ((k + 1 > j) ? 1 : dp[k+1][j]) + dp[k][k];
                    root[i][j] = k;
                }
            }
        }
    }
    std::cout << dp[0][n-1] << nl;
    auto dfs = [&](auto self, int l, int r) -> void {
        if (l == r) {
            std::cout << l + 1 << " ";
            return;
        }else if (l > r) {
            return;
        }
        int rt = root[l][r];
        std::cout << rt + 1 << " ";
        self(self, l, rt - 1);
        self(self, rt+1, r);
    };
    dfs(dfs, 0, n-1);
}
