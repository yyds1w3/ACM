//Wed Jul 22 12:19:45 PM CST 2026
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
    i64 n, m;
    std::cin >> n >> m;
    if (m >= n) {
        std::cout << (n - 2) * (n - 1) / 2 - (m - n + 1) << nl;
    }else {
        std::cout << m * (m - 1) / 2 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
