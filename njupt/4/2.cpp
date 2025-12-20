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
int n, m;
int vis[35][35];   
ll memo[35][35];   

ll dfs(int sx, int sy){
  
    if (sx > n || sy > n) return 0;
    if (vis[sx][sy] == 2) return 0;
    if (sx == n && sy == n) return 1;
    if (memo[sx][sy] != -1) return memo[sx][sy];
    memo[sx][sy] = dfs(sx + 1, sy) + dfs(sx, sy + 1);
    return memo[sx][sy];
}

void solve() {
    cin >> n >> m;
    memset(memo, -1, sizeof(memo));
    memset(vis, 0, sizeof(vis)); 
    for (int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        vis[x][y] = 2;
    }
    cout << dfs(1, 1) << endl;
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
