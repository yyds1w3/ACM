//Sat May  2 03:54:11 PM CST 2026
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> ans(31);
    std::vector<int> lst(31);
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 30; j >= 0; --j) {
            if (((a[i] >> j) & 1) != ((b[i] >> j) & 1)) {
                ans[j] ^= 1;
                lst[j] = i;
            }
        }
    }
    for (int j = 30; j >= 0; --j) {
        if (ans[j] != 0) {
            if (lst[j] & 1) {
                std::cout << "Mai" << nl;
                return;
            }else {
                std::cout << "Ajisai" << nl;
                return;
            }
        }
    }
    std::cout << "Tie" << nl;
}

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
        solve();
    }
}
