//2026-04-11 15:07:17
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
    #endif
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        i64 val;
        std::cin >> val;
        a[i] -= val;
    }
    int ans = std::count(a.begin(), a.end(), 0);
    int dp = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i] == a[i - 1]) {
            dp++;
        }else {
            dp = 1;
        }
        ans = std::max(ans, dp);
    }
    std::cout << ans << nl;
}
