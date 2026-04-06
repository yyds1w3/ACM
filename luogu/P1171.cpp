#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
const int MAXN = 20;
int g[MAXN][MAXN];
int dp[1 << MAXN][MAXN];
int n;
int f(int s, int i) {
    if (s == (1 << n) - 1) {
        return g[i][0];
    }
    if (dp[s][i] != 0x3f3f3f3f) {
        return dp[s][i];
    }
    for (int j = 0; j < n; ++j) {
        if ((s >> j) & 1) continue;
        dp[s][i] = std::min(dp[s][i], g[i][j] + f(s + (1 << j), j));
    }
    return dp[s][i];
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> g[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    std::cout << f(1, 0) << nl;


}
