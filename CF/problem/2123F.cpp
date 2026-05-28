//Tue May 26 07:11:16 PM CST 2026
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
        std::vector<int> ans(n + 1);
        std::iota(ans.begin() + 1, ans.end(), 1);
        // 找到第一个最小质因数j, ans[i] 和 ans[i/j] 的gcd== i/j 如果ans[i/j]之前没有交换, 否则就是i/j/k k是i/j的最小质因子.... > 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j * j <= i; ++j) {
                if (i % j != 0) continue;
                std::swap(ans[i], ans[i / j]);
                break;
            }
        }
        for (int i = 1; i <= n; ++i) std::cout << ans[i] << " ";
        std::cout << nl;

    }
}
