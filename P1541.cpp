//Fri Apr 17 12:14:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
int dp[41][41][41][41];

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> v[i];
    }
    std::vector<int> cnt(5);
    for (int i = 1; i <= m; ++i) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }
    dp[0][0][0][0] = v[1];
    for (int a = 0; a <= cnt[1]; ++a) {
        for (int b = 0; b <= cnt[2]; ++b) {
            for (int c = 0; c <= cnt[3]; ++c) {
                for (int d = 0; d <= cnt[4]; ++d) {
                    if (a == 0 && b == 0 && c == 0 && d == 0) continue;
                    int pos = 1 + a + 2 * b + 3 * c + 4 * d;
                    if (a > 0) dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a-1][b][c][d] + v[pos]);
                    if (b > 0) dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a][b-1][c][d] + v[pos]);
                    if (c > 0) dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a][b][c-1][d] + v[pos]);
                    if (d > 0) dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a][b][c][d-1] + v[pos]);
                }
            }
        }
    }
    std::cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << nl;
}
