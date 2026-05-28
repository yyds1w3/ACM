//Mon May 25 07:49:27 PM CST 2026
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
        int n, j, k;
        std::cin >> n >> j >> k;
        j--;
        std::vector<int> a(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            mx = std::max(mx, a[i]);
        }
        if (a[j] < mx && k == 1) {
            std::cout << "NO" << nl;
        }else {
            std::cout << "YES" << nl;
        }
    }
}
