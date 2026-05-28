//Mon Apr 20 06:07:14 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    k = n * n - k;
    if (k == 1) {
        std::cout << "No" << nl;
        return;
    }else {
        std::cout << "Yes" << nl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (k > 0) {
                    k -= 1;
                    if (i == 0 && j == 0) std::cout << 'R';
                    else if (i == 0) std::cout << 'L';
                    else std::cout << 'U';
                }else {
                    std::cout << 'D';
                }
            }
            std::cout << nl;
        }
    }
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
    while(t--) {
        solve();
    }
}
