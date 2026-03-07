#include <bits/stdc++.h>
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
const int MAXN = 2e5 + 5;
string now[5];
string target[5] = {
    "11111",
    "01111",
    "00*11",
    "00001",
    "00000"
};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int get_h() {
    int res = 0;
    rep(i, 0, 4) {
        rep(j, 0, 4) {
            if (now[i][j] != '*' && now[i][j] != target[i][j]) {
                res++;
            }
        }
    }
    return res;
}
bool dfs(int mx_dep, int g, int x, int y, int pre_dir) {
    int h = get_h();
    if (h == 0) return true;
    if (g + h > mx_dep) return false;
    rep(i, 0, 7) {
        if (pre_dir != -1 && abs(pre_dir - i) == 4) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
        swap(now[x][y], now[nx][ny]);
        if (dfs(mx_dep, g+1, nx, ny, i)) return true;
        else swap(now[x][y], now[nx][ny]);
    }
    return false;
    
}
void solve() {
    int sx = 0, sy = 0;
    rep(i, 0, 4) {
        cin >> now[i];
        rep(j, 0, 4) {
            if (now[i][j] == '*') {
                sx = i;
                sy = j;
            }
        }
    }
    int mx_dep = 15;
    rep(i, 0, 15) {
        if (dfs(i, 0, sx, sy, -1)) {
            cout << i << nl;
            return;
        }
    }
    cout << -1 << nl;
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
