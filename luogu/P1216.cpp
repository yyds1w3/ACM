#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXN = 1e3 + 1;
int dp[MAXN][MAXN];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int r; cin >> r;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    int ans = 0;
    for (int j = 1; j <= r; ++j) {
        ans = max(ans, dp[r][j]);
    }
    cout << ans << nl;
}
