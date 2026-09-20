//Mon Jul 27 07:51:32 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, W;
    std::cin >> n >> W;
    std::vector<int> v(n), w(n), m(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i] >> w[i] >> m[i];
    }
    std::vector<std::pair<i64, i64>> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 30; ++j) {
            if (m[i] >= (1 << j)) {
                m[i] -= (1 << j);
                k.push_back({1LL * v[i] * (1 << j), 1LL * w[i] * (1 << j)});
            }else break;
        }
        if (m[i] > 0) {
            k.push_back({1LL * v[i] * m[i], 1LL * w[i] * m[i]});
        }
    }
    std::vector<i64> dp(W + 1);
    for (int i = 0; i < (int)k.size(); ++i) {
        for (int j = W; j >= k[i].second; --j) {
            dp[j] = std::max(dp[j], dp[j - k[i].second] + k[i].first);
        }
    }
    std::cout << dp[W] << nl;
}
