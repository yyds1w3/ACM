#include <bits/stdc++.h>
#include <deque>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
string mp[MAXN];
int h, w;
int a, b, c, d;
int dist[MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[MAXN][MAXN];
void bfs(){
    deque<pair<int, int>> dq; 
    rep(i, 0, h-1) {
        rep(j, 0, w-1) {
            dist[i][j] = INF;
            vis[i][j] = false;
        }
    }
    dq.push_back({a-1,b-1});
    dist[a-1][b-1] = 0;
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        if (vis[x][y] == true) continue;
        vis[x][y] = true;
        rep(i, 0, 3) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > h-1 || ny < 0 || ny > w-1) continue;
            if (mp[nx][ny] == '.' && dist[nx][ny] > dist[x][y]) {
                dist[nx][ny] = dist[x][y];
                dq.push_front({nx, ny});
            }
        }
        rep(i, 0, 3) {
            rep(step, 1, 2) {
                int nx = x + dx[i] * step;
                int ny = y + dy[i] * step;
                if (nx < 0 || nx > h-1 || ny < 0 || ny > w-1) continue;
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back({nx, ny});
                }
            }
        }
    }
}
void solve() {
    cin >> h >> w;
    rep(i, 0, h-1) cin >> mp[i];
    cin >> a >> b >> c >> d;
    bfs();
    cout << dist[c-1][d-1] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
