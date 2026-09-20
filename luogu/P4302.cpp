//Thu Aug  6 09:03:35 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[101][101];
const int INF = 0x3f3f3f3f;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int n = s.size();
    s = ' ' + s;

    auto f = [&](int l, int r, int ll) {
        for (int i = l; i <= r; ++i) {
            if (s[i] != s[l + (i - l) % ll]) {
                return false;
            }
        }
        return true;
    };
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) dp[i][i] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
            for (int k = 1; k <= len / 2; ++k) {
                if (len % k != 0) continue;
                if (f(i, j, k)) {
                    int times = 0;
                    int d = len / k;
                    while (d) {
                        d /= 10;
                        times++;
                    }
                    dp[i][j] = std::min(dp[i][j], dp[i][i+k-1] + 2 + times);
                }
            }
        }
    }
    std::cout << dp[1][n] << nl;

}
