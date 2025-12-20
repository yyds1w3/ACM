// dfs + dp
// vis[mx][my][1] = x, vis[mx][my][2] = y, vis[mx][my][0] = ture?false;
// mx == (x % n + n) % n
// my == (y % m + m) % m
#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MAXN = 1501;
char a[MAXN][MAXN];
int vis[MAXN][MAXN][3];
int sx, sy;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool flag;
int n, m;
void dfs(int sx, int sy, int sxm, int sym){
    if (flag) return;
    if (vis[sxm][sym][0]){
        if (vis[sxm][sym][1] != sx || vis[sxm][sym][2] != sy)
            flag = true;
        return;
    }
    vis[sxm][sym][0] = 1;
    vis[sxm][sym][1] = sx;
    vis[sxm][sym][2] = sy;

    for (int i = 0; i < 4; ++i){
        int ex = (sx + dx[i]);
        int ey = (sy + dy[i]);
        int exm = (ex % n + n) % n;
        int eym = (ey % m + m) % m;
        if (a[exm][eym] != '#')
            dfs(ex, ey, exm, eym);
    }
}
void solve() {
    while (cin >> n >> m){
        flag = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cin >> a[i][j];
                if (a[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                vis[i][j][0] = vis[i][j][1] = vis[i][j][2] = 0;
            }
        }
        dfs(sx, sy, sx, sy);
        cout << (flag ? "Yes\n" : "No\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
