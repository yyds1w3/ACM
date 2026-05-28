//Sun Apr 26 09:43:55 AM CST 2026
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
    std::string ans = "";
    for (int i = 0, n = s.size(); i < n; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ans += s[i];
        }else if (s[i] == 'D'){
            if (!ans.empty()) {
                ans.pop_back();
            }
        }
    }
    if (!ans.empty()) {
        std::cout << ans << nl;
    }else {
        std::cout << "!!!!" << nl;
    }
}
