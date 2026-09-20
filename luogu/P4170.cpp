//Thu Aug  6 08:32:18 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const int INF = 0x3f3f3f3f;
int dp[51][51];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int n = s.size();
    s = ' ' + s;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) dp[i][i] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = std::min(dp[i+1][j], dp[i][j-1]);
            }else {
                for (int k = i; k < j; ++k) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }
    }
    std::cout << dp[1][n] << nl;
}
