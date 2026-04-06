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
    i64 n, k;
    std::cin >> n >> k;
    k++, n++;
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) { // he shu
            std::cout << 2 << nl;
            return 0;
        }
    }
    if (k * 2 <= n) {
        std::cout << 2 << nl;
    }else {
        std::cout << 1 << nl;
    }
}
