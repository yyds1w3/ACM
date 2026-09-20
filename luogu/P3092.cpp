//Tue Aug  4 07:41:27 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int k, n;
    std::cin >> k >> n;
    i64 tot = 0;
    std::vector<int> coin(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> coin[i];
        tot += coin[i];
    }

    std::vector<int> a(n), pref(n+1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    i64 ans = -1;
    std::vector<int> dp(1<<k);
    for (int mask = 0; mask < (1<<k); ++mask) {
        int l = dp[mask];
        for (int i = 0; i < k; ++i) {
            if (!((mask >> i) & 1)) {
                int r = std::upper_bound(pref.begin(), pref.end(), pref[l] + coin[i]) - pref.begin() - 1;
                dp[mask | (1 << i)] = std::max(dp[mask | (1 << i)], r);
            }
        }
        if (dp[mask] == n) {
            i64 tmp = tot;
            for (int i = 0; i < k; ++i) {
                if ((mask >> i) & 1) {
                    tmp -= coin[i];
                }
            }
            ans = std::max(ans, tmp);
        }
    }
    std::cout << ans << nl;
}
