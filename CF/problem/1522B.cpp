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
int a[MAXN][6];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cin >> a[i][j];
        }
    }
    int winner = 1;
    for (int i = 2; i <= n; ++i) {
        int win_cnt = 0;
        for (int j = 1; j <= 5; ++j) {
            if (a[i][j] < a[winner][j]) {
                win_cnt++;
            }
        }
        if (win_cnt >= 3) winner = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (i == winner) continue;
        int win_cnt = 0;
        for (int j = 1; j <= 5; ++j) {
            if (a[i][j] < a[winner][j]) {
                win_cnt++;
            }
        }
        if (win_cnt >= 3) {
            cout << "-1\n";
            return;
        }
    }
    cout << winner << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
