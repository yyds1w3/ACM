//Mon May 25 01:54:23 PM CST 2026
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
        int n = s.size();
        bool f = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != s[i + 1]) {
                f = true;
                break;
            }
        }
        if (f) {
            std::cout << "YES" << nl;
            std::cout << s.substr(1) << s[0] << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
