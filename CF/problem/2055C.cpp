//Mon Jun  1 01:47:01 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<i64>> a(n, std::vector<i64>(m));
    std::vector<i64> rsum(n + 1), csum(m + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            rsum[i + 1] += a[i][j];
            csum[j + 1] += a[i][j];
        }
    }
    int i = 0, j = 0;
    for (char c : s) {
        if (c == 'D') {
            a[i][j] = -rsum[i + 1];
            rsum[i + 1] = 0;
            csum[j + 1] += a[i][j];
            i++;
        }else if (c == 'R') {
            a[i][j] = -csum[j + 1];
            csum[j + 1] = 0;
            rsum[i + 1] += a[i][j];
            j++;
        }
    }
    a[n - 1][m - 1] = -rsum[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
