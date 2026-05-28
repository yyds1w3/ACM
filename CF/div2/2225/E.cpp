//Wed Apr 22 03:41:10 PM CST 2026
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
    int n, r;
    std::cin >> n >> r;
    std::vector<std::pair<int, int>> p(n);
    int a = 1e9, b = -1e9, c = 1e9, d = -1e9;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i].first >> p[i].second;
        a = std::min(a, p[i].first);
        b = std::max(b, p[i].first);
        c = std::min(c, p[i].second);
        d = std::max(d, p[i].second);
    }
    std::vector<std::pair<int, int>> v;
    int dist = std::ceil(std::sqrt(3) * r);
    int cnt = 0;
    for (int i = a; i - r < b; i += r) {
        cnt++; 
        int j;
        if (cnt & 1) j = c;
        else j = c + dist;
        for (; j - r < d; j += 2 * dist) {
            bool f = 0;
            for (auto [x, y] : p) {
                if (1LL * (x - i) * (x - i) + 1LL * (y - j) * (y - j) <= 1LL * r * r) {
                    f = true;
                    break;
                }
            }
            if (f) v.push_back({i, j});
        }
    }
    std::cout << v.size() << nl;
    for (auto [x, y] : v) {
        std::cout << x << " " << y << nl;
    }

}
