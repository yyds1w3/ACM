//Sun May 17 12:31:36 PM CST 2026
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
std::vector<i64> dp[10][10];
void solve() {
    i64 a, n;
    std::cin >> a >> n;
    int x1, x2;
    std::cin >> x1 >> x2;
    const auto& vec = dp[x1][x2];
    auto it = std::lower_bound(vec.begin(), vec.end(), a);
    i64 ans1 = (it != vec.begin()) ? *std::prev(it) : -1;
    i64 ans2 = (it != vec.end()) ? *it : (i64)2e18; // 三目运算符要猜类型
    if (ans1 != -1 && ans2 != (i64)2e18) {
        std::cout << (a - ans1 <= ans2 - a ? a - ans1 : ans2 - a) << nl;
    } else if (ans1 != -1) {
        std::cout << a - ans1 << nl;
    } else {
        std::cout << ans2 - a << nl;
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    for (int x1 = 0; x1 <= 8; ++x1) {
        for (int x2 = x1 + 1; x2 <= 9; ++x2) {
            std::queue<i64> q;
            if (x1 != 0) {
                q.push(x1);
                dp[x1][x2].push_back(x1);
            }else {
                dp[x1][x2].push_back(0);
            }
            q.push(x2);
            dp[x1][x2].push_back(x2);
            while (!q.empty()) {
                i64 cur = q.front();
                q.pop();

                if (cur <= (i64)1e17) {
                    i64 nxt1 = cur * 10 + x1;
                    i64 nxt2 = cur * 10 + x2;
                    q.push(nxt1);
                    q.push(nxt2);
                    dp[x1][x2].push_back(nxt1);
                    dp[x1][x2].push_back(nxt2);
                }
            }
        }
    }
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
