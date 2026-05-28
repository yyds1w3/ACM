//Thu Apr 30 10:51:20 PM CST 2026
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
        std::vector<int> a(n);
        std::vector<int> a6, a2, a3, a1;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] % 6 == 0) {
                a6.push_back(a[i]);
            }else if (a[i] % 2 == 0) {
                a2.push_back(a[i]);
            }else if (a[i] % 3 == 0) {
                a3.push_back(a[i]);
            }else a1.push_back(a[i]);
        }
        for (int v : a6) {
            std::cout << v << " ";
        }
        for (int v : a2) {
            std::cout << v << " ";
        }
        for (int v : a1) {
            std::cout << v << " ";
        }
        for (int v : a3) {
            std::cout << v << " ";
        }
        std::cout << nl;
    }
}
