//Tue Aug 11 08:51:07 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int INF = 1e9;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> d[i];
    }
    int Q;
    std::cin >> Q;
    while (Q--) {
        int k;
        std::cin >> k;
        std::vector<int> dp(n), q(n);
        int head = 0, tail = -1;
        for (int i = 1; i < n; ++i) {
            while (head <= tail && (dp[i-1] < dp[q[tail]] || (dp[i-1] == dp[q[tail]] && d[i-1] >= d[q[tail]]))) tail--;
            q[++tail] = i - 1;
            while (head <= tail && q[head] + k < i) head++;
            if (head <= tail) dp[i] = dp[q[head]] + (d[i] >= d[q[head]] ? 1 : 0);
        }
        std::cout << dp[n-1] << nl;
    }

}
