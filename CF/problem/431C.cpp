#include <bits/stdc++.h>
#include <cstring>
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
const int MOD = 1e9 + 7;
int n, k, d; // total , edge, limit
ll memo[MAXN][2];
ll dfs(int nn, bool met) {
    if (nn == 0) return met;
    if (memo[nn][met] != -1) return memo[nn][met];
    ll ans = 0;
    for (int i = 1; i <= min(nn, k); ++i) {
        ans = (ans + dfs(nn - i, (i >= d) || met)) % MOD;
    }
    return memo[nn][met] = ans;
}
void solve() {
    cin >> n >> k >> d;
    memset(memo, -1, sizeof(memo));
    cout << dfs(n, 0) << nl;
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
