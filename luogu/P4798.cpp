//Thu Jul 30 02:41:23 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
const int MOD = 1e6 + 7;
i64 dp[10001];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), pre(n + 1);
    for (int i = 0 ; i < n; ++i) {
        std::cin >> a[i];
        pre[i + 1] = std::max(pre[i], a[i]);
    }
    for (int i = 1; i <= n; ++i) dp[i] = 1;
    i64 ans = 1;
    // dp[j] 表示 :当i-1及以前的最大值是j, i-n之间的数字方案数
    for (int i = n; i >= 2; --i) { // 枚举第一个变小的位置
        ans = (ans + (a[i - 1] - 1) * dp[pre[i - 1]]) % MOD;
        for (int j = 1; j <= i; ++j) {
            dp[j] = (j * dp[j] + dp[j + 1]) % MOD;
        }
    }
    std::cout << ans << nl;
}
