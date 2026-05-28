//Tue Apr 21 11:06:48 PM CST 2026
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
        std::vector<std::string> s(2);
        for (int i = 0; i < 2; ++i) {
            std::cin >> s[i];
        }
        int i = 0;
        int cnt = 0;
        while (i < n) {
            if (s[0][i] == s[1][i]) {
                i++;
            } else if (i + 1 < n && s[0][i] == s[0][i + 1] && s[1][i] == s[1][i + 1]) {
                i += 2;
            } else {
                cnt++;
                i++;
            }
        }
        std::cout << cnt << nl;
    }
}
