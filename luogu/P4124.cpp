//Wed Jul 29 04:23:32 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
std::string s;
// dp[pos][u][v][state][n4][n8];
i64 dp[15][11][11][2][2][2];
i64 dfs(int pos, int u, int v, int state, int n4, int n8, bool limit) {
    if (n4 && n8) return 0;
    if (pos == s.size()) return state;
    if (!limit && dp[pos][u][v][state][n4][n8] != -1) return dp[pos][u][v][state][n4][n8];
    i64 ans = 0;
    int start = (pos == 0) ? 1 : 0;
    int up = limit ? s[pos] - '0' : 9;
    for (int i = start; i <= up; ++i) {
        ans += dfs(pos + 1, v, i, state || (u == v && v == i), n4 || (i == 4), n8 || (i == 8), limit && (i == up));
    }
    if (!limit) dp[pos][u][v][state][n4][n8] = ans;
    return ans;
}
i64 sol(i64 val) {
    if (val < 10000000000LL) return 0;
    s = std::to_string(val);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 10, 10, 0, 0, 0, 1);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    i64 L, R;
    std::cin >> L >> R;
    std::cout << sol(R) - sol(L - 1) << nl;
}
