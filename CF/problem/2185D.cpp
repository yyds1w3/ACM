//Sun May 10 02:37:36 PM CST 2026
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
        int n, m, h;
        std::cin >> n >> m >> h;
        std::vector<int> a(n), v(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<int> lstUpdate(n, -1);
        int tim = -1;
        for (int i = 0; i < m; ++i) {
            int b, c;
            std::cin >> b >> c;
            b--;
            if (lstUpdate[b] <= tim) {
                v[b] = a[b];
            }
            v[b] += c;
            if (v[b] > h) {
                tim = i;
            }
            lstUpdate[b] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (lstUpdate[i] <= tim) std::cout << a[i] << " ";
            else std::cout << v[i] << " ";
        }
        std::cout << nl;
    }
}
