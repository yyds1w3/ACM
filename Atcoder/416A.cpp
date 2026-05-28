//Mon Apr 20 07:28:53 PM CST 2026
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
    int n, l, r;
    std::string s;
    std::cin >> n >> l >> r >> s;
    l--;
    std::cout << (std::count(s.begin() + l, s.begin() + r, 'o') == r - l ? "Yes" : "No") << nl;
}
