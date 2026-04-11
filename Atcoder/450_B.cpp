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
    std::vector c(n, std::vector<int>(n));
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            std::cin >> c[i][j];
        }
    }
    for (int a = 1; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            for (int k = b + 1; k <= n; ++k) {
                if (c[a][b] + c[b][k] < c[a][k]) {
                    std::cout << "Yes" << nl;
                    return 0;
                }
            }
        }
    }
    std::cout << "No" << nl;


}
