//Thu Aug  6 03:12:20 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const int INF = 0x3f3f3f3f;
int dp[105][105];
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> d(n), pref(n+1);
    for (int i = 0; i < n; ++i) {
        std::cin >> d[i];
        pref[i+1] = pref[i] + d[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k <= j; ++k) {
                dp[i][j] = std::min(dp[i][j], dp[i+1][k] + dp[k+1][j] + (k-i+1) * (pref[j] - pref[k]) + d[i-1] * (k-i));
            }
        }
    }
    std::cout << dp[1][n] << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    int i = 1;
    while (t--) {
        std::cout << "Case #" << i << ": ";
        solve();
        i++;
    }
}
