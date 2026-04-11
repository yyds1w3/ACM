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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while(t--) {
        int n, m, a, b;
        std::cin >> n >> m >> a >> b;
        if (std::gcd(n, a) == 1 && std::gcd(m, b) == 1 && std::gcd(m, n) <= 2) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
