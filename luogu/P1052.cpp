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
    int L;
    std::cin >> L;
    int S, T, M;
    std::cin >> S >> T >> M;
    std::vector<int> stones(M + 1);
    for (int i = 1; i <= M; ++i) {
        std::cin >> stones[i];
    }
    if (S != T) {
        stones.push_back(L);
        std::sort(stones.begin() + 1, stones.end());
        int len = 71;
        std::vector<int> a(len * M + len + 1);
        int offset = 0;
        for (int i = 1; i <= M + 1; ++i) {
            if (stones[i] - stones[i - 1] > len) {
                offset += stones[i] - stones[i - 1] - len;
            }
            if (i <= M) {
                a[stones[i] - offset] = 1;
            }
        }
        L = stones.back() - offset;
        std::vector<int> dp(L + T + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= L + T; ++i) {
            for (int j = S; j <= T; ++j) {
                if (i >= j) {
                    dp[i] = std::min(dp[i], dp[i - j] + a[i]);
                }
            }
        }
        int ans = 1e9;
        for (int i = L; i < L + T; ++i) {
            ans = std::min(ans, dp[i]);
        }
        std::cout << ans << nl;
    }else {
        int ans = 0;
        for (int i = 1; i <= M; ++i) {
            if (stones[i] % S == 0) {
                ans++;
            }
        }
        std::cout << ans << nl;
    }

}
