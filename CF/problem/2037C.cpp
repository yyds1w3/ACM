//Wed Jun 17 07:29:35 PM CST 2026
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
    int n;
    std::cin >> n;
    if (n <= 4) {
        std::cout << -1 << nl;
    }else {
        for (int i = 2; i <= n; i += 2) {
            if (i != 4) {
                std::cout << i << " ";
            }
        }
        std::cout << 4 << " " << 5 << " ";
        for (int i = 1; i <= n; i += 2) {
            if (i != 5) {
                std::cout << i << " ";
            }
        }
        std::cout << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
