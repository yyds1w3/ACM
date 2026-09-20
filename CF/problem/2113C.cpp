//Thu Jun 11 07:52:14 PM CST 2026
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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    std::vector<std::vector<int>> pref(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pref[i + 1][j + 1] = (s[i][j] == 'g') - pref[i][j] + pref[i][j + 1] + pref[i + 1][j];
        }
    }
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                int ri = std::min(i + k, n);
                int rj = std::min(j + k, m);
                int li = std::max(i - k + 2, 1);
                int lj = std::max(j - k + 2, 1);
                mn = std::min(mn, pref[ri][rj] - pref[ri][lj - 1] - pref[li - 1][rj] + pref[li - 1][lj - 1]);
            }
        }
    }
    std::cout << pref[n][m] - mn << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
