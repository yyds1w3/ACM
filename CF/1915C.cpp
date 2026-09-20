//Wed Jul 22 03:30:24 PM CST 2026
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
    int n;
    std::cin >> n;
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        sum += x;
    }
    i64 sq = std::sqrt(sum);
    if (sq * sq == sum || (sq - 1) * (sq - 1) == sum || (sq + 1) * (sq + 1) == sum) {
        std::cout << "YES" << nl;
        return;
    }
    std::cout << "NO" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
