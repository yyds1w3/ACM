// 不用dfs(擅长曲线), 直接循环沿着一个方向走
// 用path来染色
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
int n;
char mat[101][101];
bool res[101][101];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1,1, 0, -1};
vector<pair<int, int>> path;
string target = "yizhong";
void dfs(int x, int y, int d){
    vector<pair<int, int>> path;
    for (int k = 0; k < 7; ++k){
        if (x < 1 || x > n || y < 1 || y > n) return;
        if (mat[x][y] != target[k]) return;
        path.push_back({x, y});
        x += dx[d];
        y += dy[d];
    }
    for (auto p : path){
        res[p.first][p.second] = true;
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
        for (int j = 1; j <= n; ++j){
            if (mat[i][j]=='y'){
                for (int k = 0; k < 8; ++k){
                    dfs(i, j, k);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (res[i][j] == true) cout << mat[i][j];
            else cout << "*";
        }
        cout << '\n';
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
