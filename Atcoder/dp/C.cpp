#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
int v[MAXN][3];
int dp[MAXN][3];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        rep(j, 0, 2) dp[i][j] = 0;
    } 
    rep(i, 1, n) { // day
        rep(j, 0, 2) { // dp[i][j]
            rep(k, 0, 2) {  
                if (k != j) dp[i][j] = max(dp[i][j], dp[i-1][k] + v[i][k]);
            }
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << nl;

    
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
