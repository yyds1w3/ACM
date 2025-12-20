#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
ll memo[8][3][3][3][3][3][3];
// 把w看成深度, i1....c3看作状态, dp[]看作值
ll dfs(int w, int i1, int i2, int i3, int c1, int c2, int c3){
    if (i1 > 2 || i2 > 2 || i3 > 2 || c1 > 2 || c2 > 2 || c3 > 2) return 0; // 边界约束
    if (w == 7) return (i1 == 2 && i2 == 2 && i3 == 2 && c1 == 2 && c2 == 2 && c3 == 2); // 终点
    if (memo[w][i1][i2][i3][c1][c2][c3] != -1) return memo[w][i1][i2][i3][c1][c2][c3]; // 剪枝
    ll res = 0;
    for (int d1 = 0; d1 < 3; ++d1){ // 0不打， 1打icpc， 2打ccpc
        for (int d2 = 0; d2 < 3; ++d2){
            for (int d3 = 0; d3 < 3; ++d3){
                if (d1 == 1 && d2 == 1 && d3 == 1) continue; // 约束2
                if (d1 == 2 && d2 == 2 && d3 == 2) continue; // 约束2
                res += dfs(w + 1, i1 + (d1==1), i2 + (d2==1), i3 + (d3==1), c1 + (d1==2), c2 + (d2==2), c3 + (d3==2));
            }
        }
    }
    return memo[w][i1][i2][i3][c1][c2][c3] = res;
}
void solve() {
    memset(memo, -1, sizeof(memo));
    cout << dfs(0, 0, 0, 0, 0, 0, 0);

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
