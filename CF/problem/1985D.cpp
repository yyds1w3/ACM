//Fri May 22 08:38:07 PM CST 2026
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
        std::vector<std::string> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<int> c0(n), c1(m);
        for (int i = 0; i < n; ++i) c0[i] = std::count(a[i].begin(), a[i].end(), '#');
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == '#') {
                    c1[j]++;
                }
            }
        }
        int mx = 0;
        int mi = 0, mj = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mx < c0[i] + c1[j]) {
                    mx = c0[i] + c1[j];
                    mi = i;
                    mj = j;
                }
            }
        }
        std::cout << mi + 1 << " " << mj + 1 << nl;
    }
}
