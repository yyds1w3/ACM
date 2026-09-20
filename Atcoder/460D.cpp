//Sat May 30 08:55:53 PM CST 2026
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
const int INF = 1e9;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    i64 n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    i64 cnt = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        cnt += std::count(a[i].begin(), a[i].end(), '#');
    }
    if (cnt == 0 || cnt == n * m) {
        for (int i = 0; i < n; ++i) {
            std::cout << std::string(m, '.') << nl;
        }
    }else {
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '.') {
                    bool f = false;
                    for (int x = i - 1; x <= i + 1; ++x) {
                        if (x < 0 || x >= n) continue;
                        for (int y = j - 1; y <= j + 1; ++y) {
                            if (y < 0 || y >= m) continue;
                            if (a[x][y] == '#') {
                                f = true;
                            }
                        }
                    }
                    if (f) {
                        dist[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dist[i][j] & 1) {
                    std::cout << '#';
                }else {
                    std::cout << '.';
                }
            }
            std::cout << nl;
        }
        std::cout << nl;
    }
}
