//Tue Apr 21 10:30:40 PM CST 2026
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

        i64 a, b;
        std::cin >> a >> b;
        if (b != a * 2) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
