//Sat May  2 04:33:50 PM CST 2026
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
        i64 n, k;
        std::cin >> n >> k;
        std::vector<i64> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        // x / y == a
        // x % y == b
        // xmin = a * y + b = a * (b + 1) + b = a + b + ab;
        int l = 0, r = n - 1;
        int cnt = 0;
        while (l < n && r >= 0) {
            if (a[l] + b[r] + a[l] * b[r] <= k) {
                l++;
                r--;
                cnt++;
            }else {
                r--;
            }
        }
        std::cout << cnt << nl;
    }
}
