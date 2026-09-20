//Mon Aug 17 11:23:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 1e6;
void solve() {
    i64 s, q;
    std::cin >> s >> q;
    i64 m = std::sqrt(s);
    std::vector<i64> h(m + 1);
    std::vector<i64> pref(m + 1);
    for (i64 i = 1; i <= m; ++i) {
        if (s % i == 0) {
            i64 k = s / i;
            h[i] = k;
            if (k <= m) h[k] = i;
            else h[m] = std::max(h[m], i);
        }
    }
    for (int i = m - 1; i >= 1; --i) {
        h[i] = std::max(h[i], h[i + 1]);
    }
    for (int i = 1; i <= m; ++i) {
        pref[i] = pref[i - 1] + h[i];
    }
    auto calc = [&](i64 x, i64 y) -> i64 {
        i64 l = 1, r = x + 1;
        while (l < r) {
            i64 mid = (l + r) >> 1;
            if (h[mid] > y) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        return pref[x] - (pref[r-1] - (r-1) * y);
    };
    while (q--) {
        i64 x, y;
        std::cin >> x >> y;
        i64 ans;
        if (x <= m && y <= m) {
            ans = calc(x, y);
        }else if (x <= m && y > m) {
            ans = calc(x, y);
        }else if (x > m && y <= m) {
            ans = calc(y, x);
        }else {
            ans = calc(m, x) + calc(m, y) - calc(m, m);
        }
        std::cout << ans << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
