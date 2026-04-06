#include <bits/stdc++.h>
using i64 = long long;
#define nl "\n"
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int n;
    if (!(std::cin >> n)) return 0;
    std::vector<i64> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; 
        sum += a[i];
    }
    auto getMax2Seg = [&](int l, int r) -> i64 {
        int len = r - l + 1;
        if (len < 2) return -1e18;
        std::vector<i64> L(len), R(len);
        i64 cur = -1e18, mx = -1e18;
        for (int i = 0; i < len; ++i) {
            cur = std::max(a[l + i], cur + a[l + i]);
            mx = std::max(mx, cur);
            L[i] = mx;
        }
        cur = -1e18, mx = -1e18;
        for (int i = len - 1; i >= 0; --i) {
            cur = std::max(a[l + i], cur + a[l + i]);
            mx = std::max(mx, cur);
            R[i] = mx;
        }
        i64 res = -1e18;
        for (int i = 0; i < len - 1; ++i) {
            res = std::max(res, L[i] + R[i + 1]);
        }
        return res;
    };
    i64 ans = getMax2Seg(0, n - 1);
    if (n >= 4) {
        for (int i = 1; i < n - 1; ++i) {
            a[i] = -a[i];
        }
        i64 min_val = -getMax2Seg(1, n - 2); 
        ans = std::max(ans, sum - min_val);
    }
    std::cout << ans << nl;
    return 0;
}
