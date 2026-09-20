//Tue Jun  9 08:33:46 PM CST 2026
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

    i64 len = n;
    i64 cnt = 1;
    i64 ans = 0;
    while (len >= k) {
        if (len & 1) {
            ans += (n + 1) * cnt / 2;
        }
        len >>= 1;
        cnt <<= 1;
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
