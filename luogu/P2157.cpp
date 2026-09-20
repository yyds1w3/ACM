//Wed Aug  5 03:07:57 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const int INF = 0x3f3f3f3f;
int dp[2][1<<8][16];
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }
    memset(dp, INF, sizeof(dp));
    dp[0][0][7] = 0;
    int val = 0;
    for (int i = 0; i < n; ++i, val ^= 1) {
        memset(dp[val^1], INF, sizeof(dp[val^1]));
        for (int j = 0; j < (1 << 8); ++j) {
            for (int k = 0; k < 16; ++k) {
                if (dp[val][j][k] == INF) continue;
                if (j & 1) {
                    dp[val^1][j>>1][k-1] = std::min(dp[val^1][j>>1][k-1], dp[val][j][k]);
                }else {
                    int up = INF;
                    for (int h = 0; h < 8; ++h) {
                        if (!((j >> h) & 1)) {
                            if (i + h >= n || i + h > up) break;
                            up = std::min(up, i + h + b[i + h]);
                            dp[val][j|(1<<h)][h+8] = std::min(dp[val][j|(1<<h)][h+8], dp[val][j][k] + (i+k-8<0 ? 0 : (a[i+k-8] ^ a[i+h])));
                        }
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int k = 0; k < 16; ++k) {
        ans = std::min(ans, dp[val][0][k]);
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
