#include <bits/stdc++.h>
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
const int MAXN = 55;
int a[MAXN][MAXN];
int fa[MAXN * MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int find(int x) {
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) fa[rx] = ry;
}
int get_id(int x, int y) {
    return x * MAXN + y;
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n * MAXN + m; ++i) fa[i] = i;
    vector<pair<int,int>> good, bad;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x; cin >> x;
            if (x == '.') a[i][j] = 0;
            else if (x == '#') a[i][j] = 1;
            else if (x == 'G') {a[i][j] = 0; good.push_back({i, j});}
            else if (x == 'B') {a[i][j] = 0; bad.push_back({i, j});}
        }
    }
    for (auto& [i, j] : bad) {
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            a[ni][nj] = 1;
        }
    }
    if (a[n][m] == 1 && !good.empty()) {cout << "NO" << nl; return;}
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 1) continue;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 1 && ni <= n && nj >= 1 && nj <= m && a[ni][nj] == 0)
                    merge(get_id(i, j), get_id(ni, nj));
            }
        }
    }
    int target = find(get_id(n, m));
    for (auto& [i, j] : good) {
        if (a[i][j] == 1 || (find(get_id(i, j)) != target)) {cout << "NO" << nl; return;}
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
