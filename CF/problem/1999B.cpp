//Fri May 22 07:19:07 PM CST 2026
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
        int a1, a2, b1, b2;
        std::cin >> a1 >> a2 >> b1 >> b2;
        int t1 = ((a1 > b1) && (a2 >= b2)) || ((a1 >= b1) && (a2 > b2));
        int t2 = ((a1 > b2) && (a2 >= b1)) || ((a1 >= b2) && (a2 > b1));
        int t3 = ((a2 > b1) && (a1 >= b2)) || ((a2 >= b1) && (a1 > b2));
        int t4 = ((a2 > b2) && (a1 >= b1)) || ((a2 >= b2) && (a1 > b1));
        std::cout << t1 + t2 + t3 + t4 << nl;
    } 
}
