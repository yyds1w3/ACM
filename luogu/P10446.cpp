//Tue Jul 14 02:42:19 PM CST 2026
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
    i64 a, b, p;
    std::cin >> a >> b >> p;
    i64 ans = 0;
    for (int i = 0; i < 63; ++i) {
        if ((b >> i) & 1) ans = (ans + a) % p;
        a = a * 2 % p;
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
