#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, d, k;
    std::cin >> n >> d >> k;
    std::vector<int> x(n + 1), s(n + 1);
    i64 sum = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i] >> s[i];
        sum += (s[i] > 0 ? s[i] : 0);
    }
    if (sum < k) {
        std::cout << -1 << nl;
        return 0;
    }
    auto check = [&] (int g) -> bool {
        std::vector<i64> dp(n + 1, -1e18);
        dp[0] = 0;
        int L = std::max(1, d - g);
        int R = d + g;
        int cur = 0;
        std::vector<int> q(n);
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; ++i) {
            while (cur < i && x[i] - x[cur] >= L) {
                if (dp[cur] != -1e18) {
                    while (hh <= tt && dp[q[tt]] <= dp[cur]) {
                        tt--;
                    }
                    q[++tt] = cur;
                }
                cur++;
            }
            while (hh <= tt && x[q[hh]] < x[i] - R) {
                hh++;
            }
            if (hh <= tt) {
                dp[i] = dp[q[hh]] + s[i];
                if (dp[i] >= k) return true;
            }
        }
        return false;
    };
    int l = 0, r = x[n - 1];
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    std::cout << l << nl;
}
