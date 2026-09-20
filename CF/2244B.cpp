//Wed Jul 22 07:08:19 PM CST 2026
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
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        if (i == 0) {
            i64 t = a[i] - 1;
            a[i] -= t;
            a[i + 1] += t;
        }else {
            if (a[i] <= a[i - 1]) {
                std::cout << "NO" << nl;
                return;
            }
            i64 t = a[i] - a[i - 1] - 1;
            a[i] -= t;
            a[i + 1] += t;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] >= a[i + 1]) {
            std::cout << "NO" << nl;
            return;
        }
    }
    std::cout << "YES" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
