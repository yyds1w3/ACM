//Tue Aug 11 03:01:20 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
i64 dp[100001];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> e(n + 1), pref(n + 1), q(n + 1), val(n + 1);
    int head = 0, tail = -1;
    for (int i = 1; i <= n; ++i) {
        std::cin >> e[i];
        pref[i] = pref[i - 1] + e[i];
    }
    q[++tail] = 0;
    for (int i = 1; i <= n; ++i) {
        while (head <= tail && q[head] + k < i) head++;
        int j = q[head];
        dp[i] = std::max(dp[i - 1], val[j] + pref[i]);
        val[i] = dp[i-1] - pref[i];
        while (head <= tail && val[i] >= val[q[tail]]) tail--;
        q[++tail] = i;
    }
    std::cout << dp[n] << nl;
}
