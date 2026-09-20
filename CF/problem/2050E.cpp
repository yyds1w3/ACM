//Tue Jun  9 09:22:52 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    std::string a, b, c;
    std::cin >> a >> b >> c;
    int n = a.size();
    int m = c.size();
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = n; j >= 0; --j) {
            int ma = 0;
            int mb = 0;
            if (j >= 1) ma = dp[j - 1] + (a[j - 1] == c[i]);
            if (i >= j) mb = dp[j] + (b[i - j] == c[i]);
            dp[j] = std::max(ma, mb);
        }
    }
    std::cout << m - dp[n] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
