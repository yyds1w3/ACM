//Sat May 16 12:13:32 PM CST 2026
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
        std::string s;
        std::cin >> s;
        for (int i = 0; i < 3000; ++i) {
            std::string ss;
            int idx = 0;
            while (idx < (int)s.size()) {
                if (s[idx] == s[idx + 1]) {
                    idx += 2;
                }else {
                    ss.push_back(s[idx]);
                    idx++;
                }
            }
            s = ss;
            if (s.empty()) break;
        }
        if (s.empty()) std::cout << "YES" << nl;
        else std::cout << "NO" << nl;
    }
}
