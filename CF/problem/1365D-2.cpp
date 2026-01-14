#include <bits/stdc++.h>
#include <queue>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int vis[55][55];
int n, m;
void bfs(int x, int y, vector<string>& a) {
    if (a[x][y] == '#') return;
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        auto& [cx, cy] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'B') {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (a[ni][nj] == 'G') {
                            cout << "NO" << nl;
                            return;
                        }else if (a[ni][nj] == '.' )a[ni][nj] = '#';
                    }
                }
            }
        }
    }
    bfs(n-1, m-1, a);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'G' && !vis[i][j]) {
                cout << "NO" << nl;
                return;
            } 
        }
    }
    cout << "YES" << nl;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
