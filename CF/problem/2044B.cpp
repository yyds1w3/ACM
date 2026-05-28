//Thu May 14 07:01:48 PM CST 2026
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
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 'p') {
                std::cout << 'q';
            }else if (s[i] == 'q') {
                std::cout << 'p';
            }else std::cout << 'w';
        }
        std::cout << nl;
    }
}
