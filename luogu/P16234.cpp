//2026-04-11 14:50:42
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
    #endif
    int T;
    std::cin >> T;
    while (T--) {
        i64 N, X, Y;
        std::cin >> N >> X >> Y;
        std::cout << std::max(0LL, Y - X + 1) << nl;
    }
}
