//Tue Jun 23 07:48:42 PM CST 2026
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
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    int ans = 0;
    for (int i = 0 ; i < n; ++i) {
        if (a[i] > b[i]) {
            bool f = false;
            for (int j = i + 1; !f && (j < n); ++j) {
                if (a[j] <= b[i]) {
                    f = true;
                    ans += j - i;
                    for (int k = j - 1; k >= i; --k) {
                        std::swap(a[k], a[k + 1]);
                    }
                }
            }
            if (f == false) {
                std::cout << -1 << nl;
                return;
            }
        }
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
