//Wed Jun 17 01:50:29 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    if ((n - k) % 2 == 0) {
        int l = a[(n - k) / 2 - 1];
        int r = a[n - (n - k) / 2];
        std::cout << r - l + 1 << nl;
    }else {
        k--;
        int l = a[(n - k) / 2 - 1];
        int r = a[n - (n - k) / 2];
        std::cout << r - l + 1 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
