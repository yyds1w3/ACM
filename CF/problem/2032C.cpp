//Mon Jun  1 08:00:09 PM CST 2026
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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int mx = 0;
    for (int i = 0; i < n - 2; ++i) {
        int j = std::lower_bound(a.begin(), a.end(), a[i] + a[i + 1]) - a.begin();
        mx = std::max(mx, j - i);
    }
    std::cout << n - mx << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
