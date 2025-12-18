/**
 * Algorithm: bfs
 * Verified: P1825
 * Author: Qingw
 */
#include <bits/stdc++.h>
#include <cctype>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =============start=========================
const int MAXN = 300 + 1;
struct BFS{
    char mp[MAXN][MAXN];
    int dist[MAXN][MAXN];
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    map<char, vector<pair<int, int>>> transport;
    void bfs(int sx, int sy, int n, int m){
        memset(dist, -1, sizeof(dist));
        dist[sx][sy] = 0;
        queue<pair<int, int>> q;
        q.push({sx, sy});
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            if (mp[now.first][now.second] == '='){
                cout << dist[now.first][now.second];
                return;
            }
            for (int i = 0; i < 4; ++i){
                int ex = now.first + dx[i];
                int ey = now.second + dy[i];
                if (ex < 1 || ex > n || ey < 1 || ey > m) continue;
                if (mp[ex][ey] == '#') continue;
                if (mp[ex][ey] >= 'A' && mp[ex][ey] <= 'Z'){
                    pair<int, int> nxt;
                    if (pair<int, int>(ex, ey) == transport[mp[ex][ey]].front()){
                        nxt = transport[mp[ex][ey]].back();
                    }else{
                        nxt = transport[mp[ex][ey]].front();
                    }
                    ex = nxt.first;
                    ey = nxt.second;
                }
                if (dist[ex][ey] != -1) continue;
                dist[ex][ey] = dist[now.first][now.second] + 1;
                q.push({ex, ey});
            }
        }
        cout << -1;
    }
}B;

// ==============end==========================
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, sx, sy;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> B.mp[i][j];
            if (B.mp[i][j] == '@'){
                sx = i;
                sy = j;
            }else if (isupper(B.mp[i][j])){
                B.transport[B.mp[i][j]].push_back({i, j});
            }
        }
    }
    B.bfs(sx, sy, n, m);
}
