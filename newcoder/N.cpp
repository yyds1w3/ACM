//Wed Jul 22 12:37:17 PM CST 2026
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
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + a[i];
    }
    if (k & 1) {
        int start = k / 2 + 1;
        i64 sp = s[start - 1];
        i64 diff = -2e18;
        for (int i = start; i <= n - k / 2; ++i) {
            i64 ss = s[i + k / 2] - s[i - 1];
            diff = std::max(diff, k * a[i - 1] - sp - ss);
        }
        std::cout << diff + s[n] << nl;
    }else {
        int start = k / 2 + 1;
        i64 sp = s[start - 2];
        i64 diff = -2e18;
        for (int i = start; i <= n - k / 2 + 1; ++i) {
            i64 ss = s[i + k / 2 - 1] - s[i - 2];
            diff = std::max(diff, k * (a[i - 1] + a[i - 2]) / 2 - sp - ss);
        }
        std::cout << diff + s[n] << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
