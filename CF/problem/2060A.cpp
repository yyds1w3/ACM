//Mon Jun  1 08:09:01 PM CST 2026
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
    int a1, a2, a4, a5;
    std::cin >> a1 >> a2 >> a4 >> a5;
    int mx = 0;
    for (int i = -1000; i <= 1000; ++i) {
        mx = std::max(mx, (a1 + a2 == i) + (a2 + i == a4) + (i + a4 == a5));
    }
    std::cout << mx << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
