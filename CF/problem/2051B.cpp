//Wed Jun 10 09:32:24 PM CST 2026
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
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    int d = a + b + c;
    int t1 = n / d;
    int ans = 3 * t1;
    n -= t1 * d;
    if (n > 0) {
        n -= a;
        ans++;
    } 
    if (n > 0) {
        n -= b;
        ans++;
    }
    if (n > 0) {
        n -= c;
        ans++;
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
