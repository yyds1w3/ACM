//Wed May 27 05:26:47 PM CST 2026
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
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        std::vector<std::pair<int, int>> ops;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                std::swap(a[i], b[i]);
                ops.push_back({3, i});
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (a[j] > a[j + 1]) {
                    std::swap(a[j], a[j + 1]);
                    ops.push_back({1, j});
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (b[j] > b[j + 1]) {
                    std::swap(b[j], b[j + 1]);
                    ops.push_back({2, j});
                }
            }
        }
        int k = ops.size();
        std::cout << k << nl;
        for (int i = 0; i < k; ++i) {
            std::cout << ops[i].first << " " << ops[i].second+1 << nl;
        }
    }
}
