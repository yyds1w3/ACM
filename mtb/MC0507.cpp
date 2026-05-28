//Sun Apr 26 11:12:01 AM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
            a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i1 = 1; i1 <= n; ++i1) {
        for (int j1 = 1; j1 <= m; ++j1) {
            for (int i2 = i1; i2 <= n; ++i2) {
                for (int j2 = j1; j2 <= m; ++j2) {
                    if (a[i2][j2] - a[i1-1][j2] - a[i2][j1-1] + a[i1-1][j1-1] > (i2 - i1 + 1) * (j2 - j1 + 1) / 2) {
                        ans++;
                    }
                }
            }
        }
    }
    std::cout << ans << nl;
}
