//Fri Jun 12 01:12:43 PM CST 2026
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
    // 1 9 // c1 + c2;
    // 1 5 9 // c3
    // 1 3 5 7 9 // c2 + c1
    // 1 2 3 4 5 6 7 8 9; // c3 + c1 + c2 + c3 
    // c2 + c1 + c2 + c3 + c1 + c3 + c2 + c1 ==> 2c3 + 
    // c3 ==> c1 + c2;
    // c1 + c2 ==> c1 + c2 + c3;
    int n, k;
    std::cin >> n >> k;
    std::string a, b, c;
    c.resize(n);
    std::cin >> a >> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            c[i] = '1';
        }else {
            c[i] = '0';
        }
    }
    auto f = [&](i64 c) -> i64 {
        return c * (n - c);
    };
    i64 c1 = std::count(a.begin(), a.end(), '1');
    i64 c2 = std::count(b.begin(), b.end(), '1');
    i64 c3 = std::count(c.begin(), c.end(), '1');
    i64 ans = f(c1) + f(c2);
    i64 cnt12 = 0;
    i64 cnt3 = 1;
    while (k--) {
        ans += cnt12 * (f(c1) + f(c2)) + cnt3 * f(c3);
        i64 nx3 = 2 * cnt12;
        i64 nx12 = cnt12 + cnt3;
        cnt3 = nx3;
        cnt12 = nx12;
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
