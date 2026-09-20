//Fri May 29 03:09:54 PM CST 2026
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
const int inf = 1E9;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    int g = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        g = std::gcd(g, a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == g) {
            cnt++;
        }
    }
    if (cnt > 0) {
        std::cout << n - cnt << nl;
        return;
    }
    std::vector<int> dp(5001, inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x <= 5000; ++x) {
            int y = std::gcd(a[i], x);
            dp[y] = std::min(dp[y], dp[x] + 1);
        } 
    }
    std::cout << dp[g] - 1 + n - 1 << nl;

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
    while (t--) {
        solve();
    }
}
