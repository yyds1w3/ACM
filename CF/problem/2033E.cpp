//Mon Jun  1 06:21:46 PM CST 2026
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
    // int n;
    // std::cin >> n;
    // std::vector<int> a(n);
    // std::vector<int> p(n);
    // for (int i = 0; i < n; ++i) {
    //     std::cin >> a[i];
    //     a[i]--;
    //     p[a[i]] = i;
    // }
    // int ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (a[i] != i) { // a[j] == i;
    //         int j = a[i];
    //         int k = p[i];
    //         if (a[j] != i) { // a[j] != i; 
    //             std::swap(a[j], a[k]);
    //             p[a[j]] = j;
    //             p[a[k]] = k;
    //             ans++;
    //         }
    //     }
    // }
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
    }
    std::vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int len = 0;
        int x = i;
        while (!vis[x]) {
            vis[x] = true;
            x = a[x];
            len++;
        }
        ans += (len - 1) / 2;
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
