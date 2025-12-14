#include <bits/stdc++.h>
#include <cstring>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
int mp[6][6];
int dx[4] = {1, -1, 0, 0}; // down up right left
int dy[4] = {0, 0, 1, -1};
bool vis[6][6];
int ans;
const int INF = 0x3f3f3f3f;
int n, m, t;
void dfs(int sx, int sy, int fx, int fy){
    if (sx == fx && sy == fy){
        ans++;
        return;
    }
    for (int i = 0; i < 4; ++i){
        int ex = sx + dx[i];
        int ey = sy + dy[i];
        if (ex < 1 || ex > n || ey < 1 || ey > m) continue;
        if (mp[ex][ey] == INF) continue;
        if (!vis[ex][ey]){
            vis[ex][ey] = true;
            dfs(ex, ey, fx, fy);
            vis[ex][ey] = false;
        }
    }
}
void solve() {
    cin >> n >> m >> t;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; ++i){
        int x, y;
        cin >> x >> y;
        mp[x][y] = INF;
    }
    vis[sx][sy] = true;
    dfs(sx, sy, fx, fy);
    cout << ans;
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
