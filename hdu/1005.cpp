//Tue Jul 28 12:49:45 PM CST 2026
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
    i64 x;
    std::cin >> x;
    int mx = 0;
    for (i64 i = 2; i * i * i<= x; ++i) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        mx = std::max(mx, cnt);
    }
    if (x > 1) {
        i64 s = std::sqrt(x);
        if (s * s == x) {
            mx = std::max(mx, 2);
        }else {
            mx = std::max(mx, 1);
        }
    }
    int ans = 0;
    while (mx) {
        ans++;
        mx >>= 1;
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
