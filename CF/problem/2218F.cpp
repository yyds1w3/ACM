//Sun May 10 01:28:31 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

void solve() {
    int x, y;
    std::cin >> x >> y;
    int n = x + y;
    if ((n % 2 == 0 && x == 0) || x > y) {
        std::cout << "NO" << nl;
        return;
    }
    std::cout << "YES" << nl;
    int even = (n % 2 == 0 ? x - 1 : x);
    std::vector<int> roots;
    int idx = 2;
    for (int i = 0; i < even; ++i) {
        int u = idx++;
        int v = idx++;
        std::cout << u << " " << v << nl;
        roots.push_back(u);
    }
    while (idx <= n) {
        roots.push_back(idx);
        idx++;
    }
    for (int v : roots) {
        std::cout << 1 << " " << v << nl;
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
