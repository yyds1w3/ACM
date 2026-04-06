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

const int INF = 1e9;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, h, m;
    std::cin >> n >> h >> m;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }
    std::vector<int> dp(h + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = h; j >= 0; --j) {
            if (j - a[i] >= 0) {
                dp[j] = std::min(dp[j - a[i]], dp[j] + b[i]);
            }else {
                dp[j] = dp[j] + b[i];
            }
        }
        bool f = false;
        for (int j = 0; j <= h; ++j) {
            if (dp[j] <= m) {
                f = true;
                break;
            }
        }
        if (!f) {
            std::cout << i << nl;
            return 0;
        }
    }
    std::cout << n << nl;
}
