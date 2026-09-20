//Wed Jul 29 02:43:24 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
i64 dp[13], ten[13];
// dp[2] -> 00~99 -> 20;
// ten[1] -> 10
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    i64 a, b;
    std::cin >> a >> b;
    ten[0] = 1;
    for (int i = 1; i <= 12; ++i) {
        ten[i] = ten[i - 1] * 10;
        dp[i] = i * ten[i - 1];
    }
    auto f = [&](i64 x) -> std::vector<i64> {
        std::vector<int> num;
        std::vector<i64> cnt(10);
        while (x) {
            num.push_back(x % 10);
            x /= 10;
        }
        int len = num.size();
        for (int i = len; i >= 1; --i) {
            for (int j = 0; j <= 9; ++j) cnt[j] += dp[i - 1] * num[i - 1];
            for (int j = 0; j < num[i - 1]; ++j) cnt[j] += ten[i - 1];
            i64 s = 0;
            for (int j = i - 1; j >= 1; --j) {
                s = s * 10 + num[j - 1];
            }
            cnt[num[i - 1]] += s + 1;
            cnt[0] -= ten[i - 1];
        }
        return cnt;
    };
    auto cnt1 = f(a - 1);
    auto cnt2 = f(b);
    for (int i = 0; i < 10; ++i) {
        std::cout << cnt2[i] - cnt1[i] << " ";
    }
    std::cout << nl;
}
