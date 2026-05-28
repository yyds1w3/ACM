//Thu Apr 23 09:00:38 PM CST 2026
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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (n >= 3 && s.substr(n - 3) == "tea") {
        std::cout << "Yes" << nl;
    }else {
        std::cout << "No" << nl;
    }
}
