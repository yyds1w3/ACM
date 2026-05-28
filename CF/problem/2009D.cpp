//Tue May 19 07:18:22 PM CST 2026
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
        std::vector<std::vector<int>> a(2);
        for (int i = 0; i < n; ++i) {
            int x, y;
            std::cin >> x >> y;
            a[y].push_back(x);
        }
        std::sort(a[0].begin(), a[0].end());
        std::sort(a[1].begin(), a[1].end());
        i64 ans = 0;
        for (int i = 0; i < a[0].size(); ++i) {
            if (std::binary_search(a[1].begin(), a[1].end(), a[0][i])) {
                ans += n - 2;
            }
            if (std::binary_search(a[0].begin(), a[0].end(), a[0][i] + 2)) {
                if (std::binary_search(a[1].begin(), a[1].end(), a[0][i] + 1)) {
                    ans++;
                }
            }
        }
        for (int i = 0; i < a[1].size(); ++i) {
            if (std::binary_search(a[1].begin(), a[1].end(), a[1][i] + 2)) {
                if (std::binary_search(a[0].begin(), a[0].end(), a[1][i] + 1)) {
                    ans++;
                }
            }
        }
        std::cout << ans << nl;
    }
}
