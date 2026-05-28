//Fri May 22 07:36:44 PM CST 2026
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
        std::string s1, s2;
        std::cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '?') {
                if (j < m) {
                    s1[i] = s2[j];
                    j++;
                }else {
                    s1[i] = 'a';
                }
            }else {
                if (j < m && s1[i] == s2[j]) {
                    j++;
                }
            }
        }
        if (j == m) {
            std::cout << "YES" << nl; 
            std::cout << s1 << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
