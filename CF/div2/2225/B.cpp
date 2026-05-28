//Tue Apr 21 10:50:29 PM CST 2026
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
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                cnt++;
            }
        }
        if (cnt > 2) {
            std::cout << "NO" << nl;
        }else {
            std::cout << "YES" << nl;
        }
    }
}
