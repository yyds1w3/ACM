//Tue Aug 11 07:07:17 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const i64 INF = 2e18;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, d, k;
    std::cin >> n >> d >> k;
    std::vector<int> x(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i] >> s[i];
    }
    auto check = [&](int g) -> bool {
        i64 res = 0;
        std::vector<i64> dp(n + 1, -INF);
        dp[0] = 0;
        int L = std::max(1, d - g);
        int R = d + g;
        std::vector<int> q(n + 1);
        int head = 0, tail = -1, now = 0;
        for (int i = 1; i <= n; ++i) {
            while (now < i && x[now] + L <= x[i]) {
                if (dp[now] != -INF) {
                    while (head <= tail && dp[now] >= dp[q[tail]]) tail--;
                    q[++tail] = now;
                }
                now++;
            }
            while (head <= tail && x[q[head]] + R < x[i]) head++;
            if (head <= tail) dp[i] = dp[q[head]] + s[i];
            res = std::max(res, dp[i]);
        }
        return res >= k;
    };
    int l = 0, r = x[n] + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    if (l == x[n] + 1) {
        std::cout << -1 << nl;
    }else {
        std::cout << l << nl;
    }
}
