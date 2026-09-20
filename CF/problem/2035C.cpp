//Mon Jun  1 01:57:33 PM CST 2026
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
    std::vector<int> vis(n + 1);
    int k = std::__lg(n);
    int ans;
    if (n & 1) {
        ans = n;
        p[n - 4] = 1; // |
        p[n - 3] = 3; // &
        p[n - 2] = n - 1; // |
        // 1 | 1110 ==> 构建n
        p[n - 1] = n; // &
        for (int i = n - 4; i < n; ++i) {
            vis[p[i]] = true;
        }
        for (int i = 0, x = 1; i < n - 4; ++i) {
            while (vis[x]) {
                x++;
            }
            p[i] = x;
            vis[x] = true;
        }
    }else {
        ans = (2 << k) - 1;
        p[n - 5] = 1; // |
        p[n - 4] = (k == 2 ? 5 : 3); // &
        p[n - 3] = (1 << k) - 2; // |
        // 1 | 1110 ==> 构建n
        p[n - 2] = (1 << k) - 1; // & 
        p[n - 1] = 1 << k; // |
        for (int i = n - 5; i < n; ++i) {
            vis[p[i]] = true;
        }
        for (int i = 0, x = 1; i < n - 5; ++i) {
            while (vis[x]) {
                x++;
            }
            p[i] = x;
            vis[x] = true;
        }
    }
    std::cout << ans << nl;
    for (int i = 0; i < n; ++i) std::cout << p[i] << " ";
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
