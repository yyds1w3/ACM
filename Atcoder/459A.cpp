//Sat May 23 07:59:16 PM CST 2026
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
    int x;
    std::cin >> x;
    x--;
    std::string s = "HelloWorld";
    for (int i = 0; i < s.size(); ++i) {
        if (i != x) {
            std::cout << s[i];
        }
    }
    std::cout << nl;
}
