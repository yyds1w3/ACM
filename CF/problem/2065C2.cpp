//Thu May 14 03:15:00 PM CST 2026
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
        int n, m;
        std::cin >> n >> m;
        bool f = true;
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            std::cin >> b[i];
        }
        std::sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            int pre = (i == 0 ? -1e9 : a[i - 1]);
            int a1 = (a[i] >= pre) ? a[i] : 1e9;
            int a2;
            auto it = std::lower_bound(b.begin(), b.end(), pre + a[i]);
            if (it != b.end()) {
                a2 = *it - a[i];
            }else {
                a2 = 1e9;
            }
            a[i] = std::min(a1, a2);
            if (a[i] == 1e9) {
                f = false;
                break;
            }
        }
        if (f) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
