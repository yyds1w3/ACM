#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 405;
int a[N][N];
int dist[N][N];
int n, m, x, y;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
struct point{
    int x, y;
};
void bfs(int x, int y){
    memset(dist, 0xff, sizeof(dist));
    queue<point> q;
    dist[x][y] = 0;

    q.push({x, y});
    while (!q.empty()){
        x = q.front().x;
        y = q.front().y;
        q.pop();
        for (int i = 0; i < 8; ++i){
            int sx = x + dx[i];
            int sy = y + dy[i];
            if (sx < 1 || sx > n || sy < 1 || sy > m) continue;
            if (dist[sx][sy] == -1){
                dist[sx][sy] = dist[x][y] + 1;
                q.push({sx, sy});
            }
        }
    }
}
int main(){
    cin >> n >> m >> x >> y;
    bfs(x, y);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}