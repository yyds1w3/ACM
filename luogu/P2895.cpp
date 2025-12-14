// 预处理陨石地图, bfs
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
const int S = 305;
const int INF = 0x3f3f3f3f;
int burn[S][S];
ll dist[S][S];
int dx[4] = {0, 0, -1, 1}; // r l u d 
int dy[4] = {1, -1, 0, 0}; // r l u d
void solve() {
    int M; cin >> M;
    debug(M);
    memset(burn, 0x3f, sizeof(burn));
    for (int i = 0; i < M; ++i){
        int x, y, t;
        cin >> x >> y >> t;
        burn[x][y] = min(burn[x][y], t);
        for (int j = 0; j < 4; ++j){
            int ex = x + dx[j];
            int ey = y + dy[j];
            if (ex < 0 || ex >= S || ey < 0 || ey >= S) continue;
            burn[ex][ey] = min(burn[ex][ey], t);
        }
    }
    if (burn[0][0] == 0) {cout << "-1" << '\n'; return;}
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()){
        auto now = q.front();
        q.pop();
        int sx = now.first, sy = now.second;
        for (int i = 0; i < 4; ++i){
            int ex = sx + dx[i];
            int ey = sy + dy[i];
            if (ex < 0  || ey < 0 || ex >= S || ey >= S) continue;
            if (dist[ex][ey] == -1 && dist[sx][sy] + 1 < burn[ex][ey]){
                dist[ex][ey] = dist[sx][sy] + 1;
                q.push({ex, ey});
            }
            if (burn[ex][ey] == INF) {cout << dist[ex][ey] << '\n' ;return;}
        }
    }
    cout << "-1" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
