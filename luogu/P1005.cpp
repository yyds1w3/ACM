//Thu Aug  6 07:58:45 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

i128 dp[81][81];
void print(i128 x) {
    if (x == 0) {
        std::cout << 0;
        return;
    }
    std::string s;
    while (x) {
        s += x % 10 + '0';
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
        }
    }
    i128 ans = 0;
    for (int row = 1; row <= n; ++row) {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= m; ++j) {
            dp[j][j] = a[row][j] * ((i128)1<<m);
        }
        for (int len = 2; len <= m; ++len) {
            for (int i = 1; i + len - 1 <= m; ++i) {
                int j = i + len - 1;
                dp[i][j] = std::max({dp[i][j], dp[i+1][j] + a[row][i]*((i128)1<<(m-len+1)), dp[i][j-1] + a[row][j]*((i128)1<<(m-len+1))});
            }
        }
        ans += dp[1][m];
    }
    print(ans);
    std::cout << nl;
}
