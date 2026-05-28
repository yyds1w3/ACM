//Mon May 18 09:13:24 PM CST 2026
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
        std::string s;
        std::cin >> s;
        int ans = 0;
        int p = 0;
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (s[i] == '4') ans++;
            if (s[i] == '1' || s[i] == '3') p++;
            if (s[i] == '2' && p > 0) {
                p--;
                ans++;
            }
        }
        std::cout << ans << nl;
    }
}
