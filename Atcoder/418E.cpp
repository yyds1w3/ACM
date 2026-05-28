//Fri Apr 24 03:35:57 PM CST 2026
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
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first >> a[i].second;
    }
    std::vector<std::pair<int, int>> slopes;
    std::vector<std::pair<int, int>> mids;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int dx = a[i].first - a[j].first;
            int dy = a[i].second - a[j].second;
            int sumX = a[i].first + a[j].first;
            int sumY = a[i].second + a[j].second;
            mids.push_back({sumX, sumY});
            int g = std::gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            slopes.push_back({dx, dy});
        } 
    }
    auto f = [&](std::vector<std::pair<int, int>>& v) -> i64 {
        if (v.empty()) return 0;
        std::sort(v.begin(), v.end());
        int cnt = 1;
        i64 ans = 0;
        for (int i = 1, sz = v.size(); i < sz; ++i) {
            if (v[i] == v[i - 1]) {
                cnt++;
            }else {
                ans += (i64)cnt * (cnt - 1) / 2;
                cnt = 1;
            }
        }
        ans += (i64)cnt * (cnt - 1) / 2;
        return ans;
    };
    std::cout << f(slopes) - f(mids) << nl;
}
