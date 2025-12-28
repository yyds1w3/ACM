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
int m, n;
int a[100001][20];
int lg[100001];
int query(int l, int r) {
    int k = lg[r - l + 1];
    int len = 1 << k;
    return min(a[l][k], a[r-len+1][k]);
}
void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m ; ++i) {
        cin >> a[i][0];
    }
    for (int k = 1; k <= 20; ++k) {
        for (int i = 1; i + (1 << k) - 1 <= m; ++i) {
            a[i][k] = min(a[i][k-1], a[i + (1 << (k-1))][k-1]);
        }
    }
    lg[1] = 0;
    for (int i = 2; i <= 100000; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << " ";
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
