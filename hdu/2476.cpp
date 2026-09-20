//Thu Aug  6 02:26:16 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[101][101];
const int INF = 0x3f3f3f3f;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string a, b;
    while (std::cin >> a >> b) {
        int m = b.size();
        a = ' ' + a;
        b = ' ' + b;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == j) dp[i][j] = 1;
                else if (i > j) dp[i][j] = 0;
                else if (i < j) dp[i][j] = INF;
            }
        }
        for (int len = 2; len <= m; ++len) {
            for (int i = 1; i + len - 1<= m; ++i) {
                int j = i + len - 1;
                if (b[i] == b[j]) {
                    dp[i][j] = std::min({dp[i][j], dp[i+1][j], dp[i][j-1]});
                }
                for (int k = i; k < j; ++k) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }
        for (int j = 1; j <= m; ++j) {
            if (a[j] == b[j]) {
                dp[1][j] = dp[1][j-1];
            }else {
                for (int k = 1; k < j; ++k) {
                    dp[1][j] = std::min(dp[1][j], dp[1][k] + dp[k+1][j]);
                }
            }
        }
        std::cout << dp[1][m] << nl;
    }
}
