//Tue Apr 28 08:09:02 PM CST 2026
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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::vector<int> b = a;
        std::sort(b.begin(), b.end());
        int m = b[n/2];
        
        std::vector<int> dp(n + 1, -1e9);
        dp[0] = 0;
        for (int r = 1; r <= n; ++r) {
            int neg = 0, zero = 0, pos = 0;
            for (int l = r - 1; l >= 0; --l) {
                if (a[l] < m) neg++;
                else if (a[l] > m) pos++;
                else zero++;
                if ((r - l) % 2 == 0) continue;
                if (zero > std::abs(neg - pos)) {
                    dp[r] = std::max(dp[r], dp[l] + 1);
                }
            }
        }
        std::cout << dp[n] << nl;
    }
}
