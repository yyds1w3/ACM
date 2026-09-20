//Wed Jun 10 09:35:40 PM CST 2026
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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i];
    }
    std::vector<bool> vis(n + 1);
    for (int i = 0; i < k; ++i) {
        int x;
        std::cin >> x;
        vis[x] = true;
    }
    if (k < n - 1) {
        std::cout << std::string(m, '0') << nl;
        return;
    }
    if (k == n) {
        std::cout << std::string(m, '1') << nl;
        return;
    }
    for (int i = 0; i < m; ++i) {
        if (vis[a[i]]) {
            std::cout << 0;
        }else {
            std::cout << 1;
        }
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
