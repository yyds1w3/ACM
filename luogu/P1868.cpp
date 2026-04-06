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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    int mxY = 0;
    std::vector straws(3000002, std::vector<int>());
    for (int i = 1; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        x++, y++;
        mxY = std::max(mxY, y);
        straws[y].push_back(x);
    }
    std::vector<int> dp(mxY + 1);
    for (int i = 1; i <= mxY; ++i) {
        dp[i] = dp[i - 1];
        for (auto x : straws[i]) {
            dp[i] = std::max(dp[i], dp[x - 1] + i - x + 1);
        }
    }
    std::cout << dp[mxY] << nl;
    

}
