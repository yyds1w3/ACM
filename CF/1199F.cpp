//Thu Aug  6 04:06:27 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[51][51][51][51];
int mp[51][51];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c;
            std::cin >> c;
            if (c == '#') {
                mp[i][j] = 1;
                dp[i][j][i][j] = 1;
            }
        }
    }
    for (int lx = 1; lx <= n; ++lx) {
        for (int ly = 1; ly <= n; ++ly) {
            if (lx == 1 && ly == 1) continue;
            for (int x1 = 1; x1 + lx - 1 <= n; ++x1) {
                for (int y1 = 1; y1 + ly - 1 <= n; ++y1) {
                    int x2 = x1 + lx - 1;
                    int y2 = y1 + ly - 1;
                    dp[x1][y1][x2][y2] = std::max(x2-x1, y2-y1) + 1;
                    for (int kx = x1; kx < x2; ++kx) {
                        dp[x1][y1][x2][y2] = std::min(dp[x1][y1][x2][y2], dp[x1][y1][kx][y2] + dp[kx+1][y1][x2][y2]);
                    }
                    for (int ky = y1; ky < y2; ++ky) {
                        dp[x1][y1][x2][y2] = std::min(dp[x1][y1][x2][y2], dp[x1][y1][x2][ky] + dp[x1][ky+1][x2][y2]);
                    }
                }
            }
        }
    }
    std::cout << dp[1][1][n][n] << nl;
}
