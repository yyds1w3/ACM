//Sat May  2 08:03:42 PM CST 2026
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
    std::vector<std::vector<int>> a(3, std::vector<int>(6));
    std::vector<std::vector<int>> cnt(3, std::vector<int>(7));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cin >> a[i][j];
            cnt[i][a[i][j]]++;
        }
    }
    double ans = (double)cnt[0][4] * cnt[1][5] * cnt[2][6] / 216 + 
        (double)cnt[0][4] * cnt[1][6] * cnt[2][5] / 216 +
        (double)cnt[0][5] * cnt[1][4] * cnt[2][6] / 216 +
        (double)cnt[0][5] * cnt[1][6] * cnt[2][4] / 216 +
        (double)cnt[0][6] * cnt[1][4] * cnt[2][5] / 216 +
        (double)cnt[0][6] * cnt[1][5] * cnt[2][4] / 216; 
    std::cout << ans << nl;

}
