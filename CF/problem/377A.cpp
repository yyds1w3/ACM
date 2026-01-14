#include <bits/stdc++.h>
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
const int MAXN = 1e5 + 5;
int n, m, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[501][501];
char ma[501][501];
bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int ex = x + dx[i];
        int ey = y + dy[i];
        if (!valid(ex, ey)) continue;
        if (ma[ex][ey] == '.' && !vis[ex][ey]){
            dfs(ex, ey);
        }
    }
    if (k > 0) {
        k--;
        ma[x][y] = 'X';
    }
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> ma[i][j];
    }
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ma[i][j] == '.') {dfs(i, j);flag = 1; break;}
        }
        if (flag) break;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << ma[i][j];
        cout << nl;
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
    while (tt--) solve();
}
