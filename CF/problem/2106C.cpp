//Fri May 29 04:20:46 PM CST 2026
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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        if (std::count(b.begin(), b.end(), -1) == n) {
            int mn = *std::max_element(a.begin(), a.end());
            int mx = *std::min_element(a.begin(), a.end()) + k;
            std::cout << mx - mn + 1 << nl;
        }else {
            int tar = -1;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if (b[i] != -1) {
                    if (tar == -1) {
                        tar = a[i] + b[i];
                    }else {
                        if (tar != a[i] + b[i]) {
                            ok = false;
                        }
                    }
                }
            }
            if (!ok) std::cout << 0 << nl;
            else {
                for (int i = 0; i < n; ++i) {
                    if (b[i] == -1) {
                        b[i] = tar - a[i];
                        if (b[i] < 0 || b[i] > k) {
                            ok = false;
                        }
                    }
                }
                if (ok) std::cout << 1 << nl;
                else {
                    std::cout << 0 << nl;
                }
            }
        }
    }
}
