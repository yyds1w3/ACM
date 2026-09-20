//Tue Jul 28 02:38:32 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
int dp[41][41][41][41];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::vector<int> cnt(4);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        cnt[x - 1]++;
    }
    dp[cnt[0]][cnt[1]][cnt[2]][cnt[3]] = arr[0];
    for (int a = cnt[0]; a >= 0; --a) {
        for (int b = cnt[1]; b >= 0; --b) {
            for (int c = cnt[2]; c >= 0; --c) {
                for (int d = cnt[3]; d >= 0; --d) {
                    int pos = cnt[0] - a + 2 * (cnt[1] - b) + 3 * (cnt[2] - c) + 4 * (cnt[3] - d);
                    if (a < cnt[0]) dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a + 1][b][c][d] + arr[pos]);
                    if (b < cnt[1]) dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a][b + 1][c][d] + arr[pos]);
                    if (c < cnt[2]) dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a][b][c + 1][d] + arr[pos]);
                    if (d < cnt[3]) dp[a][b][c][d] = std::max(dp[a][b][c][d], dp[a][b][c][d + 1] + arr[pos]);
                }
            }
        }
    }
    std::cout << dp[0][0][0][0] << nl;
}
