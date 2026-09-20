//Sat Jun 20 04:47:49 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> map(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            std::cin >> c;
            map[i][j] = c - '0';
        }
    }
    std::string s;
    int i = 0, j = 0, d = 0;
    int ans = 0;
    while (map[i][j] != -1) {
        s += map[i][j] + '0';
        map[i][j] = -1;
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx >= n || nx < 0 || ny >= m || ny < 0 || map[nx][ny] == -1) {
            if (d == 3) {
                s += s.substr(0, 3);
                for (int k = 0; k < (int)s.size() - 3; ++k) {
                    if (s.substr(k, 4) == "1543") {
                        ans++;
                    }
                }
                s.clear();
            }
            d = (d + 1) % 4;
            nx = i + dx[d];
            ny = j + dy[d];
        }
        i = nx;
        j = ny;
    }
    if (!s.empty()) {
        s += s.substr(0, 3);
        for (int k = 0; k < (int)s.size() - 3; ++k) {
            if (s.substr(k, 4) == "1543") {
                ans++;
            }
        }
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
