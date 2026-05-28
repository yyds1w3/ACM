//Tue May 19 01:14:40 PM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        // i 的下一集的位置
        std::vector<int> nxt1(n, n), nxt2(n, n), nx1(n, n), nx2(n, n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        // a[i] 的位置
        std::vector<int> lst(n + 2, n);
        for (int i = n - 1; i >= 0; --i) {
            nxt1[i] = lst[a[i] + 1];
            lst[a[i]] = i;
            nx1[i] = lst[1];
        }
        lst.assign(n + 2, n);
        for (int i = n - 1; i >= 0; --i) {
            nxt2[i] = lst[b[i] + 1];
            lst[b[i]] = i;
            nx2[i] = lst[1];
        }
        // 如果在i看了一集, 他们的右边界
        std::vector<int> dp(n + 1, n);
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == b[i]) {
                int x = nxt1[i];
                int y = nxt2[i];
                if (x != y) dp[i] = std::min(x, y);
                else dp[i] = dp[x];
            }
        }
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = nx1[i];
            int y = nx2[i];
            if (x != y) {
                ans += std::min(x, y) - i;
            }else {
                ans += dp[x] - i;
            }
        }
        std::cout << ans << nl;
    }
}
