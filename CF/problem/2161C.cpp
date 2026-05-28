//Mon May  4 07:46:19 PM CST 2026
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
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        std::vector<int> path;
        int l = 0, r = a.size() - 1;
        int s = 0;
        i64 ans = 0;
        while (l <= r) {
            if (s + a[r] >= x) {
                s = (s + a[r]) % x;
                path.push_back(a[r]);
                ans += a[r];
                r--;
            }else {
                s = (s + a[l]) % x;
                path.push_back(a[l]);
                l++;
            }
        }
        std::cout << ans << nl;
        for (int v : path) {
            std::cout << v << " ";
        }
        std::cout << nl;
    }
}
