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
    int N;
    std::cin >> N;
    std::vector<int> dp(N);
    dp.assign(N, 1);
    std::vector<std::string> s(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> s[i];
        for (int j = 0; j < i; ++j) {
            if (s[i].find(s[j]) == 0) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
                ans = std::max(ans, dp[i]);
            }
        }
    }
    std::cout << ans << nl;
}
