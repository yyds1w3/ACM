//Sat May 30 12:46:18 PM CST 2026
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
std::vector<int> dp(2e5 + 1);
void init() {
    for (int i = 1; i <= 2e5; ++i) {
        int temp = i;
        int ans = 0;
        while (temp) {
            ans += temp % 10;
            temp /= 10;
        }
        dp[i] = ans + dp[i - 1];
    }
}
void solve() {
    int n;
    std::cin >> n;
    std::cout << dp[n] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    init();
    while (t--) {
        solve();
    }
}
