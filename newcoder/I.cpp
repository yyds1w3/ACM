//Wed Aug 12 12:19:02 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) std::cin >> a[i];
    i64 t = a[0] + m;
    i64 ans1 = 0;
    if (a[1] > t) ans1++;
    for (int i = 2; i < 2 * n; i += 2) {
        i64 x = std::max(a[i], a[i + 1]);
        i64 y = std::min(a[i], a[i + 1]);
        if (y > t) ans1 += 2;
        else if (x > t || x + y + m > 2 * t) {
            ans1++;
        }
    }
    i64 ans2 = 0;
    t = a[0];
    if (a[1] + m > t) ans2++;
    for (int i = 2; i < 2 * n; i += 2) {
        i64 x = std::max(a[i], a[i + 1]);
        i64 y = std::min(a[i], a[i + 1]);
        x = std::min(x, t);
        if (x + y + m > 2 * t) ans2 += 2;
        else if (x + m > t) ans2++;
    }
    std::cout << ans1 << " " << ans2 << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
