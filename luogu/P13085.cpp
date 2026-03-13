#include <bits/stdc++.h>
#include <cstring>
#include <string>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
i64 dp[20][10]; // dp[pos][pre] // 在pos位置上， 前一位是pre的总和情况
std::string s;
i64 dfs(int pos, int pre, int lead, int limit) {
    if (pos == s.size()) return (lead == 1) ? 0 : 1;
    if (!limit && !lead && dp[pos][pre] != -1) return dp[pos][pre];
    int up = limit ? s[pos] - '0' : 9;
    i64 ans = 0;
    for (int i = 0; i <= up; ++i) {
        if (lead || abs(i - pre) >= 2) {
            ans += dfs(pos + 1, i, lead && (i == 0), limit && (i == up));
        }
    }
    if (!limit && !lead) dp[pos][pre] = ans;
    return ans;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 a, b, ans = 0;
    std::cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    s = std::to_string(b);
    ans += dfs(0, 0, 1, 1);
    memset(dp, -1, sizeof(dp));
    s = std::to_string(a-1);
    ans -= dfs(0, 0, 1, 1);
    std::cout << ans << nl;
}
