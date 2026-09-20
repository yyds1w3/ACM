//Fri Jun  5 04:36:22 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n, k;
    std::cin >> n >> k;
    k %= n;
    if (n % 2 == 0 && (k & 1)) {
        std::cout << -1 << nl;
    }else {
        if (n % 2 == 0) {
            if (k == 0) {
                std::cout << 0 << nl;
            }else {
                std::cout << (n - k) / 2 << nl;
            }
        }else {
            if (k == 0) {
                std::cout << 0 << nl;
            }else if (k & 1) {
                std::cout << (n - k) / 2 << nl;
            }else {
                std::cout << n / 2 + 1 + (n - 1 - k) / 2 << nl;
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
