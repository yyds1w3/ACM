//Wed Aug 19 12:42:05 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
#define debugv(v, sz) std::cerr << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cerr << v[i] << " "; std::cerr << nl;
#define debugvv(v, sz1, sz2) std::cerr << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cerr << i << ":";for (int j = 0; j < sz2; ++j) std::cerr << v[i][j] << " "; std::cerr<<nl;}
using i64 = long long;
using i128 = __int128;
const i64 INF = 2e18;
i64 dp[1<<24];
int g[24][24];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    n *= 3;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> g[i][j];
        }
    }
    std::fill(dp, dp + (1 << n), -INF);
    dp[0] = 0;
    for (int msk = 0; msk < (1 << n); ++msk) {
        if (dp[msk] == -INF) continue;
        int i = __builtin_ctz(~msk);
        for (int j = i + 1; j < n; ++j) {
            if (!((msk >> j) & 1)) {
                for (int k = j + 1; k < n; ++k) {
                    if (!((msk >> k) & 1)) {
                        int nxt = msk ^ (1 << i) ^ (1 << j) ^ (1 << k);
                        dp[nxt] = std::max(dp[nxt], dp[msk] + g[i][j] + g[i][k] + g[j][k]);
                    }
                }

            }
        }
    }
    std::cout << dp[(1<<n)-1] << nl;
}
