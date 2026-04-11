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
        int n, k;
        std::cin >> n >> k;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            ans += x;
        }
        if (ans % 2 == 1 || n * k % 2 == 0) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
