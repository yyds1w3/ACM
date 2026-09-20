//Sun Jun  7 04:52:07 PM CST 2026
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
    std::string s;
    std::cin >> s;
    std::vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
    }
    auto check = [&](int x) {
        int cnt = 0;
        bool f = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R' && a[i] > x) {
                if (f) {
                    cnt++;
                    f = false;
                }
            }else if (s[i] == 'B' && a[i] > x) {
                f = true;
            }
        }
        if (f) cnt++;
        return cnt <= k;
    };
    int l = 0, r = mx;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    std::cout << l << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
