//Tue May 19 09:30:15 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }
    if (std::accumulate(l.begin(), l.end(), 0) == 0) {
        std::cout << 0 << nl;
    }else {
        int L, R;
        for (int i = 0; i < n; ++i) {
            if (l[i] == 1) {
                L = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (l[i] == 1) {
                R = i;
                break;
            }
        }
        std::cout << R - L << nl;
    }
}
