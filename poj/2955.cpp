//Thu Sep 10 02:51:09 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}
const int N = 100;
int dp[N+1][N+1];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s;
    while (std::cin >> s) {
        if (s == "end") break;
        int n = s.size();
        s = ' ' + s;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                if (s[i] == '(' && s[j] == ')') dp[i][j] = std::max(dp[i][j], dp[i+1][j-1] + 2);
                else if (s[i] == '[' && s[j] == ']') dp[i][j] = std::max(dp[i][j], dp[i+1][j-1] + 2);
                for (int k = i; k < j; ++k) {
                    dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }
        std::cout << dp[1][n] << nl;
    }
}

