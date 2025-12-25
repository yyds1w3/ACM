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
const int MAXN = 5e4 + 1;
const int LOGN = 17;
int st_max[MAXN][LOGN];
int st_min[MAXN][LOGN];
int lg[MAXN];
int n, q;
int h[MAXN];
void init_st(){
    cin >> n >> q;
    for (int i = 1;i <= n; ++i) cin >> h[i];
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; ++i) st_max[i][0] = st_min[i][0] = h[i];
    for (int j = 1; j <= lg[n]; ++j){
        int len = 1 << (j - 1);
        for (int i = 1; i + (1 << j) - 1 <= n; ++i){
            st_max[i][j] = max(st_max[i][j-1], st_max[i + len][j-1]);
            st_min[i][j] = min(st_min[i][j-1], st_min[i + len][j-1]);
        }
    }
}
int query(int l, int r){
    int k = lg[r - l + 1];
    int len = 1 << k;
    int mx = max(st_max[l][k], st_max[r-len+1][k]);
    int mn = min(st_min[l][k], st_min[r-len+1][k]);
    return mx - mn;
}
void solve() {
    init_st();
    for (int i = 1; i <= q; ++i){
        int l, r; cin >> l >> r;
        cout << query(l ,r) << "\n";
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
