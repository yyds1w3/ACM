//Tue Jun  9 11:14:12 PM CST 2026
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
    for (int i = 1; i <= n; ++i) std::cout << i << " ";
    for (int i = 2; i <= n; ++i) std::cout << i << " ";
    std::cout << 1 << " ";
    for (int i = 1; i <= n; ++i) std::cout << i << " ";
    for (int i = 1; i <= n; ++i) std::cout << i << " ";
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
