//Wed Jul 29 03:33:38 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
i64 dp[15][10];
std::string s;
i64 f(int pos, int pre, bool limit, bool zero) {
    if (pos == s.size()) return zero ? 0 : 1;
    if (!limit && !zero && dp[pos][pre] != -1) return dp[pos][pre];
    i64 res = 0;
    int up = limit ? s[pos] - '0' : 9;
    for (int i = 0; i <= up; ++i) {
        if (zero || (std::abs(i - pre) >= 2)) {
            res += f(pos + 1, i, (i == up) && limit, zero && (i == 0));
        }
    }
    if (!limit && !zero) dp[pos][pre] = res;
    return res;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int a, b;
    std::cin >> a >> b;
    i64 ans = 0;
    s = std::to_string(b);
    memset(dp, -1, sizeof(dp));
    ans += f(0, 0, 1, 1);

    s = std::to_string(a - 1);
    memset(dp, -1, sizeof(dp));
    ans -= f(0, 0, 1, 1);

    std::cout << ans << nl;
}
