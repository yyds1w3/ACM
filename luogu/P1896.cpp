#include <bits/stdc++.h>
#include <cstring>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
i64 dp[9][82][1 << 9];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, k;
    std::cin >> n >> k;
    std::vector<int> valid;
    for (int s = 0, ns = (1 << n); s < ns; ++s) {
        if ((s & (s << 1)) == 0) {
            valid.push_back(s);
        }
    }
    auto dfs = [&] (auto self, int row, int king, int lstatus) ->i64 {
        if (king > k) return 0;
        if (row == n) {
            return king == k ? 1 : 0;
        }
        if (dp[row][king][lstatus] != -1) {
            return dp[row][king][lstatus];
        }
        i64 res = 0;
        for (int s : valid) {
            if ((s & lstatus) ||
                (s & (lstatus << 1)) ||
                (s & (lstatus >> 1))
            ) continue;
            int cnt = __builtin_popcount(s);
            res += self(self, row + 1, king + cnt, s);
        }
        return dp[row][king][lstatus] = res;
    };
    memset(dp, -1, sizeof(dp));
    std::cout << dfs(dfs, 0, 0, 0) << nl;

}
