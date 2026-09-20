//Tue Aug 11 04:36:57 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const i64 INF = 1e18;
i64 dp[400001];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, L, R;
    std::cin >> n >> L >> R;
    std::vector<int> a(n + 1 + R), q(n + 1 + R);
    for (int i = 0; i <= n; ++i) std::cin >> a[i];
    std::fill(dp, dp + n + R + 1, -INF);
    dp[0] = 0;
    int head = 0, tail = -1;
    for (int i = L; i <= n + R; ++i) {
        if (dp[i - L] != -INF) {
            while (head <= tail && dp[i - L] >= dp[q[tail]]) {
                tail--;
            }
            q[++tail] = i - L;
        }
        while (head <= tail && q[head] + R < i) head++;
        if (head <= tail) {
            dp[i] = dp[q[head]] + a[i];
        }
    }
    std::cout << *std::max_element(dp + n + 1, dp + n + R + 1) << nl;
}
