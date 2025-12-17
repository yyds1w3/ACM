#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
const int MAXN = 31;
int mat[MAXN][MAXN];
int tag[MAXN][MAXN];
int dx[8] = { -1,  0, 0,  1};
int dy[8] = { 0,  -1, 1,  0};
int n;
void dfs(int sx, int sy){
    if (mat[sx][sy] == 0 && tag[sx][sy] == 0) tag[sx][sy] = 1;
    for (int i = 0; i < 4; ++i){
        int ex = sx + dx[i];
        int ey = sy + dy[i];
        if (ex < 1 || ex >=n || ey < 1 || ey >=n) continue;
        if (mat[ex][ey] == 1 || tag[ex][ey] == 1) continue;
        dfs(ex, ey);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= n; ++i){
        if (mat[1][i] == 0) dfs(1, i);
        if (mat[n][i] == 0) dfs(n, i);
        if (mat[i][1] == 0) dfs(i, 1);
        if (mat[i][n] == 0) dfs(i, n);
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (mat[i][j] == 0){
                if (tag[i][j] == 1) cout << "0 ";
                else cout << "2 ";
            }else{
                cout << "1 ";
            }
        }
        cout << "\n";
    }
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
