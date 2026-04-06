#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector mp(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            std::cin >> c;
            if (c == '*') {
                mp[i][j] = 1;
            }
        }
    }
    std::vector<i64> dp(m), h(m);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<i64> stk;
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == 1) {
                h[j] = 0;
            }else {
                h[j]++;
            }
            while (!stk.empty() && h[stk.back()] >= h[j]) {
                stk.pop_back();
            }
            int k = stk.empty() ? -1 : stk.back();
            if (k == -1) {
                dp[j] = h[j] * (j + 1);
            }else {
                dp[j] = dp[k] + h[j] * (j - k);
            }
            stk.push_back(j);
            ans += dp[j]; 
        }
    }
    std::cout << ans << nl;
}
