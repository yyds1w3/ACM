//2026-04-10 17:01:18
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
    #endif
    i64 n, x, y, w;
    std::cin >> n >> x >> y >> w;
    x--, y--;
    std::vector<std::pair<i64, i64>> q(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i].first >> q[i].second;
        q[i].first--;
    }
    q[n] = {y, 0};
    std::sort(q.begin(), q.end());
    i64 ans = std::abs(x - q[0].first);
    i64 cap = 0;
    for (int i = 0; i < n; ++i) {
        cap += q[i].second;
        i64 dist = q[i + 1].first - q[i].first;
        i64 trips = 2 * ((cap + w - 1) / w) - 1;
        ans += dist * trips;
    }
    std::cout << ans << nl;
}
