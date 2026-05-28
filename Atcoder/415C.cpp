//Sun Apr 19 03:48:43 PM CST 2026
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

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> dp(1 << n);
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] == 0) continue;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) continue;
            int nxt = mask | (1 << i);
            if (s[nxt - 1] == '0') {
                dp[nxt] = 1;
            }
        }
    }
    if (dp[(1 << n) - 1]) {
        std::cout << "Yes" << nl;
    }else {
        std::cout << "No" << nl;
    }
    
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
