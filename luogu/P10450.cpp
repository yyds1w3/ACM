//Tue Jul 21 04:43:56 PM CST 2026
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
    int n, L;
    std::cin >> n >> L;
    std::vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    auto check = [&](double x) -> bool {
        std::vector<double> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + a[i] - x;
        }
        double mn = 1e9;
        for (int i = L; i <= n; ++i) {
            mn = std::min(mn, s[i - L]);
            if (s[i] - mn >= 0) {
                return true;
            }
        }
        return false;
    };
    double l = 0, r = 2000;
    for (int i = 0; i < 30; ++i) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    std::cout << (int)(r * 1000) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
