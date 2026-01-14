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
const int MAXN = 2e3 + 1;
int a[3][MAXN];
ll dp[205][205][205];
void solve() {
    int col[3]; cin >> col[0] >> col[1] >> col[2];
    for (int i = 0; i < col[0]; ++i) cin >> a[0][i];
    for (int i = 0; i < col[1]; ++i) cin >> a[1][i];
    for (int i = 0; i < col[2]; ++i) cin >> a[2][i];
    for (int i = 0; i < 3; ++i) sort(a[i], a[i] + col[i], greater<int>());
    ll ans = 0;
    for (int i = 0; i <= col[0]; ++i) {
        for (int j = 0; j <= col[1]; ++j) {
            for (int k = 0; k <= col[2]; ++k) {
                if (i && j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + a[0][i - 1] * a[1][j - 1]);
                if (i && k) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + a[0][i - 1] * a[2][k - 1]);
                if (j && k) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + a[1][j - 1] * a[2][k - 1]);
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
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
