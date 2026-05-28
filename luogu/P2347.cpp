//Thu Apr 16 10:19:35 PM CST 2026
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
    std::vector<int> a(6);
    std::vector<int> w{1, 2, 3, 5, 10, 20};
    for (int i = 0; i < 6; ++i) {
        std::cin >> a[i];
    }
    std::bitset<1001> dp;
    dp[0] = 1;
    for (int i = 0; i < 6; ++i) {
        for (int k = 0; k < a[i]; ++k) {
            dp |= (dp<< w[i]);
        } 
    }
    std::cout << "Total=" << dp.count() - 1 << nl;
}
