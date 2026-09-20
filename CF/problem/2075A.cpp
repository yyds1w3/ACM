//Thu May 28 02:49:07 PM CST 2026
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
        int n, k;
        std::cin >> n >> k;
        bool f1 = n & 1;
        bool f2 = k & 1;
        int ans;
        if (f1 == f2) {
            if (f1) {
                if (n == k) {
                    ans = 1;
                }else {
                    ans = (n - k - 1) / (k - 1) + 2;
                }
            }else {
                ans = (n - 1) / k + 1;
            }
        }else {
            if (f1) {
                ans = (n - k) / (k - 1) + 2;
            }else {
                ans = (n - k) / (k - 1) + 2;
            }
        }
        std::cout << ans << nl;
    }
}
