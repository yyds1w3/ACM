//Sun May 24 01:02:20 PM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        auto check = [&](int x) -> bool {
            int lst = 1;
            int res = 0;
            for (int i = 0; i < n; ++i) {
                int u = a[i] >= x;
                int v = b[i] >= x;
                if (u + v == 1) continue;
                if (u == 0 && lst == 0) continue;
                res += u == 1 ? 1 : -1;
                lst = u;
            }
            return res > 0;
        };
        int l = 1, r = 2 * n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) {
                l = mid;
            }else {
                r = mid - 1;
            }
        }
        std::cout << l << nl;
    }
}
