//Sun Jun  7 06:22:32 PM CST 2026
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
    for (int i = 0; i <= 9; ++i) {
        std::string s = std::to_string(n - i);
        int mx = 0;
        for (char c : s) {
            if (c <= '7') {
                mx = std::max(mx, c - '0');
            }
        }
        if (i >= 7 - mx) {
            std::cout << i << nl;
            return;
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
