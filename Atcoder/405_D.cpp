#include <bits/stdc++.h>
#include <queue>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
std::string dir = "v<^>";
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> mp(h);
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        std::cin >> mp[i];
        for (int j = 0; j < w; ++j) {
            if (mp[i][j] == 'E') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (mp[nx][ny] != '.') continue;
            if (dist[nx][ny] !=  -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            mp[nx][ny] = dir[i]; 
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cout << mp[i][j];
        }
        std::cout << nl;
    }
}
