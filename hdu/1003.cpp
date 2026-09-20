//Tue Jul 28 01:13:17 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const i64 INF = 2e18;
void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<i64> dp;
    for (int i = 0; i < n; ++i) {
        auto it = std::upper_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) {
            if (!dp.empty()) {
                dp.push_back(a[i] + dp.back());
            }else {
                dp.push_back(a[i]);
            }
        }else {
            if (it == dp.begin()) {
                *it = std::min(*it, a[i]);
            }else {
                *it = std::min(*it, *std::prev(it) + a[i]);
            }
        }
    }
    std::cout << dp.size() << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
