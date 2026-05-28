//Mon Apr 20 07:33:52 PM CST 2026
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
    std::string s, t;
    std::cin >> s;
    bool f = true;
    
    for (int i = 0, n = s.size(); i < n; ++i) {
        if (s[i] == '#') {
            t += '#';
            f = true;
        }else if (s[i] == '.'){
            if (f) {
                t += 'o';
                f = false;
            }else {
                t += '.';
            }
        }
    }
    std::cout << t << nl;
}
