//Mon Jun  1 08:15:13 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::vector<int> p(n);
    bool f = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            a[i][j] %= n;
        }
        if (std::count(a[i].begin(), a[i].end(), a[i].back()) == m) {
            p[a[i].back()] = i;
        }else {
            f = false;
        }
    }
    if (f) {
        for (int i = 0; i < n; ++i) std::cout << p[i] + 1 << " ";
        std::cout << nl;
    }else {
        std::cout << -1 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
