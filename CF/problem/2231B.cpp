//Thu May 21 11:20:56 PM CST 2026
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
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int mx = 0;
        for (int i = 0; i < n - 1; ++i) {
            mx = std::max(mx, a[i] - a[i + 1]);
        }
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                a[i] += mx;
            }
        }
        std::cout << (std::is_sorted(a.begin(), a.end()) ? "YES" : "NO") << nl;
    }
}
