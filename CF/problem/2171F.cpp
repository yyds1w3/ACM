//Fri Jun 26 03:04:14 PM CST 2026
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
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    std::vector<std::pair<int, int>> edges;
    std::vector<int> stk;
    for (int i = 0; i < n; ++i) {
        int v = p[i];
        int mn = v;
        while (!stk.empty() && stk.back() < v) {
            mn = std::min(stk.back(), mn);
            edges.push_back({stk.back(), v});
            stk.pop_back();
        }
        stk.push_back(mn);
    }
    if (stk.size() == 1) {
        std::cout << "YES" << nl;
        for (auto [u, v] : edges) {
            std::cout << u << " " << v << nl;
        }
    }else {
        std::cout << "NO" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
