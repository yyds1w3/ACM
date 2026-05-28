//Thu Apr 23 05:47:32 PM CST 2026
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
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        ans += mp[i - x];
        mp[i + x]++;
    }
    std::cout << ans << nl;

}
