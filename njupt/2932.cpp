//Mon Jul 27 01:56:57 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
int dp[51][51][51][51];
const int MOD = 998244353;
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    dp[n][0][0][0] = 1;
    for (int i = 4 * n - 1; i >= 0; --i) {
        for (int a = 0; a <= n; ++a) {
            for (int b = 0; a + b <= n; ++b) {
                for (int c = 0; a + b + c <= n; ++c) {
                    for (int d = 0; a + b + c + d <= n; ++d) {
                        if (s[i] == 'p') dp[a-1][b+1][c][d] = (dp[a-1][b+1][c][d] + dp[a][b][c][d]) % MOD;

                    }
                }
            }
        }

    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
