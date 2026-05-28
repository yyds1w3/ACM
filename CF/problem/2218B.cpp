//Sun May 10 01:02:30 PM CST 2026
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
        std::vector<int> a(7);
        for (int i = 0; i < 7; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        int ans = -std::accumulate(a.begin(), a.end() - 1, 0) + a.back();
        std::cout << ans << nl;
    }
}
