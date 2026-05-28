//Thu May 21 08:05:50 PM CST 2026
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
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        std::vector<std::vector<int>> b(n, std::vector<int>(m + 1));
        int c1 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) {
                if (a[i][j] == 1) c1++;
                b[i][j] = b[i][j + 1] + (a[i][j] == 1);
            }
        }
        int have = 0;
        std::string ans;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (true) {
                if (b[i][j] + have <= c1 / 2) {
                    have += b[i][j];
                    ans += "D";
                    break;
                }else {
                    if (j < m) {
                        j++;
                        ans += "R";
                    }else break;
                }
            }
        }
        while (j < m) {ans += "R"; j++;}
        std::cout << 1LL * have * (c1 - have) << nl;
        std::cout << ans << nl;
    }
}
