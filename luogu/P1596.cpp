// 错误原因, 是char数组不是int数组, 否则cin罢工
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
const int MAXN = 101;
char mp[MAXN][MAXN];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int sx, int sy){
    mp[sx][sy] = '.';
    for (int d = 0; d < 8; ++d){
        int ex = sx + dx[d];
        int ey = sy + dy[d];
        if (ex < 1 || ex >= MAXN || ey < 1 || ey >= MAXN) continue;
        if (mp[ex][ey] == 'W'){
            dfs(ex, ey);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    debug(n,m);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> mp[i][j];
            debug(mp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (mp[i][j] == 'W'){
                ans++;
                debug(ans);
                dfs(i,j);
            }
        }
    }
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
