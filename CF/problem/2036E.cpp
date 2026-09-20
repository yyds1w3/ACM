//Sat Jun 20 05:57:23 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<std::vector<int>> a(n, std::vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cin >> a[i][j];
        }
    }
    std::vector<std::vector<int>> b(k, std::vector<int>(n));
    for (int j = 0; j < k; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                a[i][j] |= a[i - 1][j];
            }
            b[j][i] = a[i][j];
        }
    }
    while (q--) {
        int m;
        std::cin >> m;
        int mx = n - 1;
        int mn = 0;
        for (int i = 0; i < m; ++i) {
            int r;
            std::cin >> r;
            r--;
            char o;
            std::cin >> o;
            if (o == '<') {
                int c;
                std::cin >> c;
                mx = std::min(mx, int(std::lower_bound(b[r].begin(), b[r].end(), c) - b[r].begin() - 1));
            }else {
                int c;
                std::cin >> c;
                mn = std::max(mn, int(std::upper_bound(b[r].begin(), b[r].end(), c) - b[r].begin()));
            }
        }
        if (mx >= mn) {
            std::cout << mn + 1 << nl;
        }else{
            std::cout << -1 << nl;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
