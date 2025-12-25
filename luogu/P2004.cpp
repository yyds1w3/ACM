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

ll a[1001][1001];
void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i){
        for (int j = 1;j <= m; ++j){
            cin >> a[i][j];
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
        }
    }
    ll ans = 0, ansx = 0, ansy = 0;
    for (int i = c; i <= n; ++i){
        for (int j = c; j <= m; ++j){
            if (ans < a[i][j] - a[i][j-c] - a[i-c][j] + a[i-c][j-c]){
                ans = a[i][j] - a[i][j-c] - a[i-c][j] + a[i-c][j-c];
                ansx = i + 1 - c;
                ansy = j + 1 - c;
            }
        }
    }
    cout << ansx << " " << ansy << endl;
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
