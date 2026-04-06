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
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int w, h;
    std::cin >> w >> h;
    std::vector<std::vector<int>> a(h, std::vector<int>(w));
    int rx = -1, ry = -1;
    int ex = -1, ey = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> a[i][j];
            if (a[i][j] == 2) {
                rx = i;
                ry = j;
            }else if (a[i][j] == 3) {
                ex = i;
                ey = j;
            }
        }
    }
    auto bfs1 = [&](int rx, int ry) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
        dist[rx][ry] = 0;
        std::queue<std::pair<int, int>> q;
        q.push({rx, ry});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (a[nx][ny] == 1 || a[nx][ny] == 3) continue;
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    };
    auto dist1 = bfs1(rx, ry);

    auto bfs2 = [&](int rx, int ry) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
        dist[rx][ry] = 0;
        std::queue<std::pair<int, int>> q;
        q.push({rx, ry});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (a[nx][ny] == 1) continue;
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    };
    auto dist2 = bfs2(ex, ey);
    int ans = 1e9;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == 4 && dist1[i][j] != -1 && dist2[i][j] != -1) {
                ans = std::min(ans, dist1[i][j] + dist2[i][j]);
            }
        }
    }
    std::cout << ans << nl;

}
