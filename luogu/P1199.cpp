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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        std::sort(a[i].begin(), a[i].end());
        ans = std::max(ans, a[i][n - 2]);
    }
    std::cout << 1 << nl;
    std::cout << ans << nl;
}
