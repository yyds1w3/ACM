//Tue May 12 08:46:31 PM CST 2026
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
        int odd = 0;
        int even = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] & 1) odd++;
            else even++;
        }
        if (odd != 0 && even != 0) {
            std::sort(a.begin(), a.end());
        }
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << nl;
    }
}
