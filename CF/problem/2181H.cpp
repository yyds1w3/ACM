//Sat May  2 01:50:29 PM CST 2026
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
    int w, h, d, n;
    std::cin >> w >> h >> d >> n;
    int x = std::gcd(w, n);
    n /= x;
    int y = std::gcd(h, n);
    n /= y;
    int z = std::gcd(d, n);
    n /= z;
    if (n == 1) {
        std::cout << x - 1 << " " << y - 1 << " " << z - 1 << nl;
    }else {
        std::cout << -1 << nl;
    }
}
