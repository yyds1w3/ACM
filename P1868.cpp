//Fri Apr 17 02:21:13 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> ends(3e6 + 2);
    int mxY = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        x++, y++;
        ends[y].push_back(x);
        mxY = std::max(mxY, y);
    }
    std::vector<int> dp(mxY + 2);
    for (int i = 1; i <= mxY; ++i) {
        dp[i] = dp[i - 1];
        if (ends[i].empty()) continue;
        for (int x : ends[i]) {
            dp[i] = std::max(dp[i], dp[x - 1] + i - x + 1);
        }
    }
    std::cout << dp[mxY] << nl;

}
