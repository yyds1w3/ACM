//Thu Jun 11 06:44:43 PM CST 2026
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
    int w, h, a, b;
    std::cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx == 0 && dy == 0) {
        std::cout << "Yes" << nl;
        return;
    }
    if (((dx != 0) && (dx % a == 0)) || ((dy != 0) && (dy % b == 0))) {
        std::cout << "Yes" << nl;
        return;
    }
    std::cout << "No" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
