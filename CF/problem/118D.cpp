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
const int MAXN = 1e5 + 5;
const int MOD = 1e8;
int dp[101][101][2][11]; // t == 0 foot, t == 1 house
int n1, n2, k1, k2;
void solve() {
    cin >> n1 >> n2 >> k1 >> k2;
    dp[1][0][0][1] = dp[0][1][1][1] = 1;
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            for (int t = 0; t < 2; ++t) {
                for (int n = 0; n <= 10; ++n) {
                    if (dp[i][j][t][n] == 0) continue;
                    int now = dp[i][j][t][n];
                    if (i + 1 <= n1) { // 可以用步兵
                        if (t == 0){
                            if (n + 1 <= k1) dp[i+1][j][0][n+1] = (dp[i+1][j][0][n+1] + now) % MOD;
                        } // 现在是步兵收尾
                        else 
                            dp[i+1][j][0][1] = (dp[i+1][j][0][1] + now) % MOD;
                    }
                    if (j + 1 <= n2) {
                        if (t == 0)
                            dp[i][j+1][1][1] = (dp[i][j+1][1][1] + now) % MOD;
                        else{
                            if (n+1 <= k2) dp[i][j+1][1][n+1] = (dp[i][j+1][1][n+1] + now) % MOD;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int t = 0; t < 2; ++t) {
        for (int n = 0; n < 11; ++n) {
            ans = (ans + dp[n1][n2][t][n]) % MOD;
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
