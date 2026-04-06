#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 n, m, s;
    std::cin >> n >> m >> s;
    std::vector<i64> w(n + 1), v(n + 1), l(m + 1), r(m + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> l[i] >> r[i];
    }
    auto calc = [&](i64 x) -> i64 {
        std::vector<i64> pre_w(n + 1), pre_v(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre_w[i] = pre_w[i - 1] + (w[i] >= x ? 1 : 0);
            pre_v[i] = pre_v[i - 1] + (w[i] >= x ? v[i] : 0);
        }
        i64 ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans += (pre_w[r[i]] - pre_w[l[i] - 1]) * (pre_v[r[i]] - pre_v[l[i] - 1]);
        }
        return ans;
    };
    int L = 0, R = 1e6;
    i64 mn = 2e18;
    while (L < R) {
        int mid = (L + R) >> 1;
        i64 Y = calc(mid);
        mn = std::min(mn, std::abs(Y - s));
        if (Y > s) {
            L = mid + 1;
        }else {
            R = mid;
        }
    }
    std::cout << mn << nl;
}
