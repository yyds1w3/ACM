//Sun May 31 05:36:27 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    if (n == k) {
        int ans = 1;
        for (int i = 2; i <= n; i += 2) {
            if (a[i] == ans) {
                ans++;
            }else {
                break;
            }
        }
        std::cout << ans << nl;
    }else {
        for (int i = 2; i <= n - k + 2; ++i) {
            if (a[i] != 1) {
                std::cout << 1 << nl;
                return;
            }
        }
        std::cout << 2 << nl;
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
    while (t--) solve();
}
