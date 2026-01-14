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
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;
int dp[MAXN];
int pre[MAXN];
void solve() {
    int t, k; cin >> t >> k;
    dp[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        dp[i] = (dp[i-1] + (i >= k ? dp[i-k] : 0)) % MOD;
        pre[i] = (pre[i-1] + dp[i]) % MOD;
    }
    for (int i = 1; i <= t; ++i) {
        int a, b; cin >> a >> b;
        cout << (pre[b] - pre[a-1] + MOD) % MOD << nl;
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
    while (tt--) solve();
}
