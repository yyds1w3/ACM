//Fri May  8 04:06:16 PM CST 2026
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
        int n, q;
        std::cin >> n >> q;
        std::vector<int> a(n);
        std::vector<int> pi0(n + 1), pi1(n + 1);
        std::vector<int> same;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) {
            pi0[i + 1] = pi0[i] + (a[i] == 0);
            pi1[i + 1] = pi1[i] + (a[i] == 1);
            if (i < n - 1 && a[i] == a[i + 1]) {
                same.push_back(i);
            }
        }
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            l--;
            int c0 = pi0[r] - pi0[l];
            int c1 = pi1[r] - pi1[l];
            if (c0 % 3 != 0 || c1 % 3 != 0) {
                std::cout << -1 << nl;
            }else {
                auto it = std::lower_bound(same.begin(), same.end(), l);
                if (it != same.end() && *it < r - 1) {
                    std::cout << (r - l) / 3 << nl;
                }else {
                    std::cout << 1 + (r - l) / 3 << nl;
                }
            }
        }
    }
}
