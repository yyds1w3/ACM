// bfs搜索， 传送门，最短路径 
#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif

int n, m;
char mp[301][301];
int dist[301][301];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

map<char, vector<pair<int, int>>> portals;

void bfs(int start_x, int start_y){
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));
    dist[start_x][start_y] = 0;
    q.push({start_x, start_y});
    while (!q.empty()){
        auto curr = q.front();
        q.pop();
        int ux = curr.first;
        int uy = curr.second;
        if (mp[ux][uy] == '=') {
            cout << dist[ux][uy] << endl;
            return;
        }
        for (int i = 0; i < 4; ++i){
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if (vx < 1 || vx > n || vy < 1 || vy > m) continue;
            if (mp[vx][vy] == '#') continue;
            if (mp[vx][vy] >= 'A' && mp[vx][vy] <= 'Z') {
                char letter = mp[vx][vy];
                pair<int, int> p1 = portals[letter][0];
                pair<int, int> p2 = portals[letter][1];
                if (vx == p1.first && vy == p1.second) {
                    vx = p2.first;
                    vy = p2.second;
                } else {
                    vx = p1.first;
                    vy = p1.second;
                }
            }
            if (dist[vx][vy] == -1) {
                dist[vx][vy] = dist[ux][uy] + 1;
                q.push({vx, vy});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    debug(n, m);
    int sx = 1, sy = 1;
    portals.clear();
    debug(sx, sy);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> mp[i][j];
            if (mp[i][j] == '@'){
                sx = i;
                sy = j;
            } else if (mp[i][j] >= 'A' && mp[i][j] <= 'Z'){
                portals[mp[i][j]].push_back({i, j});
            }
        }
    }
    bfs(sx, sy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef LOCAL

    if (fopen("in.txt", "r")) {

        freopen("in.txt", "r", stdin);

    }
    #endif
    solve();
    return 0;
}
