//Wed Jun 10 08:59:00 PM CST 2026
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
    int n, x, y;
    std::cin >> n >> x >> y;
    x--, y--;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[(x + i) % n] = i & 1;
    }
    if ((n & 1) || ((y - x) % 2 == 0)) {
        a[x] = 2;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
