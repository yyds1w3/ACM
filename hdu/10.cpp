//Thu Aug  6 12:08:08 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    i64 x, y;
    std::cin >> x >> y;
    if (x == 0) {
        std::cout << y * (y - 1) / 2 << nl;
    }else {
        x--;
        i64 z = std::min(x, y);
        x -= z;
        y -= z;
        i64 ans = 2 * z * z;
        debug(z);
        debug(ans);
        if (x > 0) {
            ans += x * (2 * z);
        }else {
            ans += (2 * z + 1 + 2 * z + y) * y / 2;
        }
        std::cout << ans << nl;
    }
    
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
