//Mon May 25 02:25:42 PM CST 2026
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
        std::vector<int> a(k + 1), b(k + 1);
        for (int i = 1; i <= k; ++i) std::cin >> a[i];
        for (int i = 1; i <= k; ++i) std::cin >> b[i];
        while (q--) {
            int d;
            std::cin >> d;
            int idx = std::lower_bound(a.begin(), a.end(), d) - a.begin();
            if (idx == 0) std::cout << 0 << " ";
            else std::cout << b[idx - 1] + 1LL * (d - a[idx - 1]) * (b[idx] - b[idx - 1]) / (a[idx] - a[idx - 1]) << " ";
        }
        std::cout << nl;
    }
}
