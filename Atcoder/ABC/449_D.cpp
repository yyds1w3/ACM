#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
i64 f(i64 x, i64 y) {
    if (x < 0 || y < 0) return 0;
    i64 ans = 0;
    if (x > y) std::swap(x, y);
    i64 m = x / 2;
    ans += (1 + m * 2 * 2 + 1) * (m + 1) / 2; // souxiang + moxiang * xiangshu / 2
    ans += (x + 1) * ((y / 2 + 1) - (x / 2 + 1));
    return ans;
}
i64 q(i64 x1, i64 y1, i64 x2, i64 y2) {
    return f(x2, y2) - f(x2, y1 - 1) - f(x1 - 1, y2) + f(x1 - 1, y1 - 1);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 l, r, d, u;
    std::cin >> l >> r >> d >> u;
    std::vector<std::pair<i64, i64>> X, Y;
    if (l <= r && r < 0) {
        X.push_back({-r, -l});
    }else if (l < 0 && r >= 0) {
        X.push_back({0, -l});
        X.push_back({1, r});
    }else if (l >= 0 && l <= r){
        X.push_back({l, r});
    }
    if (d <= u && u < 0) {
        Y.push_back({-u, -d});
    }else if (d < 0 && d <= u) {
        Y.push_back({0, -d});
        Y.push_back({1, u});
    }else {
        Y.push_back({d, u});
    }
    i64 ans = 0;
    for (auto [x1, x2] : X) {
        for (auto [y1, y2] : Y) {
            ans += q(x1, y1, x2, y2);
        }
    }
    std::cout << ans << nl;
}
