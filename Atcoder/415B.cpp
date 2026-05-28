//Sun Apr 19 03:44:14 PM CST 2026
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
    std::string s;
    std::cin >> s;
    int n = s.size();
    int f = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            std::cout << i + 1 << ",\n"[f];
            f ^= 1;
        }
    }
}
