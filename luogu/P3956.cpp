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

struct Point {
    int x, y, col, d;
    bool operator<(const Point& other) const {
        return d > other.d;
    }
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> col(m, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        int x, y, c;
        std::cin >> x >> y >> c;
        x--, y--, c++;
        col[x][y] = c; // 0, 1, 2;
    }
    std::vector<std::vector<std::vector<int>>> dist(m, std::vector<std::vector<int>>(m, std::vector<int>(3, 1e9)));
    auto dji = [&]() -> void {
        dist[0][0] = std::vector<int>(3, 0);
        std::priority_queue<Point> pq;
        pq.push({0, 0, col[0][0], 0});
        while (!pq.empty()) {
            auto [x, y, c, d] = pq.top();
            pq.pop();
            if (d > dist[x][y][c]) continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= m) continue;
                int cost = 0;
                int nc = 0;
                if (col[nx][ny] == 0) {
                    if (col[x][y] == 0) continue;
                    cost = 2;
                    nc = c;
                }else {
                    cost = (col[nx][ny] == c ? 0 : 1);
                    nc = col[nx][ny];
                }
                if (dist[x][y][c] + cost < dist[nx][ny][nc]) {
                    dist[nx][ny][nc] = dist[x][y][c] + cost;
                    pq.push({nx, ny, nc, dist[nx][ny][nc]});
                }
            }
        }
    };
    dji();
    int ans = 1e9;
    for (int c = 0; c < 3; ++c) {
        ans = std::min(ans, dist[m - 1][m - 1][c]); 
    }
    std::cout << (ans == 1e9 ? -1 : ans) << nl;
}
