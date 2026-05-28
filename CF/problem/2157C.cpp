//Tue May  5 04:45:21 PM CST 2026
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
        int n, k, q;
        std::cin >> n >> k >> q;
        std::vector<int> mex(n);
        std::vector<int> mn(n);
        std::vector<int> a(n);
        for (int i = 0; i < q; ++i) {
            int c, l, r;
            std::cin >> c >> l >> r;
            l--;
            if (c == 1) {
                for (int j = l; j < r; ++j) {
                    mn[j] = 1;
                }
            }else {
                for (int j = l; j < r; ++j) {
                    mex[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (mex[i] && mn[i]) a[i] = k + 1;
            else if (mex[i]) a[i] = i % k;
            else if (mn[i]) a[i] = k;
        }
        for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
        std::cout << nl;
    }
}
