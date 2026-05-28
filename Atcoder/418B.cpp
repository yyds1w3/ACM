//Thu Apr 23 09:03:15 PM CST 2026
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
    double ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 3; j <= n; ++j) {
            if (s[i] == 't' && s[j-1] == 't') {
                int x = std::count(s.begin() + i, s.begin() + j, 't');
                int sz = j - i; 
                ans = std::max(ans, double(x - 2) / (sz - 2));
            }
        }
    }
    std::cout << std::setprecision(9) << std::fixed << ans << nl;
}
