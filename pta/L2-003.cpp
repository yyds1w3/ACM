//Thu Apr 16 05:52:24 PM CST 2026
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
struct st {
    double tot, num;
    bool operator<(const st& other) const {
        return tot / num > other.tot / other.num;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    double n, d;
    std::cin >> n >> d;
    std::vector<st> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].num;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].tot;
    }
    std::sort(a.begin(), a.end());
    
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (d > 0) {
            double sold = std::min(d, a[i].num);
            d -= sold;
            ans += (double)a[i].tot / a[i].num * sold;
        }else {
            break;
        }
    }
    std::cout << std::setprecision(2) << std::fixed << ans << nl;
}
