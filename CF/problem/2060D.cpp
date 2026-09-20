//Mon Jun  1 08:35:10 PM CST 2026
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
    for (int i = 0; i < n - 1; ++i) {
        int v = std::min(a[i], a[i + 1]);
        a[i] -= v;
        a[i + 1] -= v;
    }
    if (std::is_sorted(a.begin(), a.end())) {
        std::cout << "YES" << nl;
    }else {
        std::cout << "NO" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
