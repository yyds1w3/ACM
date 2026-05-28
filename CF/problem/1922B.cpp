//Sat May 23 07:02:47 PM CST 2026
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
        std::map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            m[x]++;
        }
        i64 ans = 0;
        i64 sum = 0;
        for (auto [x, c] : m) {
            ans += 1LL * c * (c - 1) * (c - 2) / 6 + 1LL * c * (c - 1) / 2 * sum;
            sum += c;
        }
        std::cout << ans << nl;
    }
}
