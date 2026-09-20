//Fri Jun 12 10:46:36 PM CST 2026
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
    int a, b, x;
    std::cin >> a >> b >> x;
    std::vector<int> v1, v2;
    while (a) {
        v1.push_back(a);
        a /= x;
    }
    v1.push_back(0);
    while (b) {
        v2.push_back(b);
        b /= x;
    }
    v2.push_back(0);
    i64 ans = 1e18;
    for (int i = 0; i < (int)v1.size(); ++i) {
        for (int j = 0; j < (int)v2.size(); ++j) {
            ans = std::min(ans, i + j + (i64)std::abs(v1[i] - v2[j]));
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
