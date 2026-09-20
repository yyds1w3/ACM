//Tue Jun  9 10:33:30 PM CST 2026
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
    int n, x, y, z;
    std::cin >> n >> x >> y >> z;
    int t1 = (n - 1) / (x + y) + 1;
    int t2 = std::max(0, (n - z * x - 1)) / (x + 10 * y) + 1 + z; 
    std::cout << std::min(t1, t2) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
