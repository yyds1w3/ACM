//Thu May 28 12:29:25 PM CST 2026
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
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        int c0 = std::count(s.begin(), s.end(), '0');
        int c1 = std::count(s.begin(), s.end(), '1');
        
        int mx = c0 / 2 + c1 / 2;
        int mn = std::abs(c0 - c1) / 2;
        if (k <= mx && k >= mn) {
            if ((k - mn) % 2 == 0) {
                std::cout << "YES" << nl;
            }else {
                std::cout << "NO" << nl;
            }
        }else {
            std::cout << "NO" << nl;
        }
    }
}
