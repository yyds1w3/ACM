//Sat May 23 03:42:55 PM CST 2026
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
    int t, k;
    std::cin >> t >> k;
    std::vector<std::vector<int>> C(2001, std::vector<int>(2001));
    C[0][0] = 1;
    for (int i = 1; i <= 2000; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % k;
        }
    }
    std::vector<std::vector<int>> P(2001, std::vector<int>(2001)); 
    for (int i = 1; i <= 2000; ++i) {
        for (int j = 1; j <= 2000; ++j) { // 不统计j==0是因为C[i][0] == 1, 1 % k != 0, 所以一定没有贡献
            P[i][j] = -P[i-1][j-1] + P[i-1][j] + P[i][j-1] + (j <= i && C[i][j] == 0);
        }
    }
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::cout << P[n][m] << nl;
    }
}
