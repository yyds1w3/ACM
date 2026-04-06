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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Point{
    int x, y, dir, d;
    bool operator<(const Point& other) const {
        return d > other.d;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    int rx, ry, ex, ey, dir;
    char c;
    std::cin >> rx >> ry >> ex >> ey >> c;
    rx--, ry--, ex--, ey--;
    if (c == 'N') dir = 0;
    else if (c == 'E') dir = 1;
    else if (c == 'S') dir = 2;
    else if (c == 'W') dir = 3;
    std::vector<std::vector<std::vector<int>>> dist(n, std::vector<std::vector<int>>(m, std::vector<int>(4, 1e9)));
    auto dij = [&](int rx, int ry, int rdir) -> void {
        if (rx < 0 || rx >= n - 1 || ry < 0 || ry >= m - 1) return;
        if (a[rx][ry] || a[rx + 1][ry] || a[rx][ry + 1] || a[rx + 1][ry + 1]) return;
        dist[rx][ry][rdir] = 0; 
        std::priority_queue<Point> pq;
        pq.push({rx, ry, rdir, 0});
        while (!pq.empty()) {
            auto [x, y, dir, d] = pq.top();
            pq.pop();
            if (d > dist[x][y][dir]) continue;
            if (dist[x][y][dir] + 1 < dist[x][y][(dir + 1) % 4]) {
                dist[x][y][(dir + 1) % 4] = dist[x][y][dir] + 1;
                pq.push({x, y, (dir + 1) % 4, dist[x][y][(dir + 1) % 4]});
            }
            if (dist[x][y][dir] + 1 < dist[x][y][(dir + 3) % 4]) {
                dist[x][y][(dir + 3) % 4] = dist[x][y][dir] + 1;
                pq.push({x, y, (dir + 3) % 4, dist[x][y][(dir + 3) % 4]});
            }
            for (int step = 1; step <= 3; ++step) {
                int nx = x + dx[dir] * step;
                int ny = y + dy[dir] * step;
                if (nx < 0 || nx >= n - 1 || ny < 0 || ny >= m - 1) break;
                if (a[nx][ny] || a[nx + 1][ny] || a[nx][ny + 1] || a[nx + 1][ny + 1]) break;
                if (dist[x][y][dir] + 1 < dist[nx][ny][dir]) {
                    dist[nx][ny][dir] = dist[x][y][dir] + 1;
                    pq.push({nx, ny, dir, dist[nx][ny][dir]});
                }
            }
        }
    };
    dij(rx, ry, dir);
    int ans = 1e9;
    for (int di = 0; di < 4; ++di) {
        ans = std::min(ans, dist[ex][ey][di]);
    } 
    std::cout << (ans == 1e9 ? -1 : ans) << nl;
}
