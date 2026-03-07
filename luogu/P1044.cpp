#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
int memo[20][20];
int dfs(int i, int j) {
    if (i == 0 && j == 0) return 1;
    if (memo[i][j] != 0) return memo[i][j];
    int cnt = 0;
    if (i > 0) cnt += dfs(i-1, j);
    if (j > 0) cnt += dfs(i+1, j-1);
    return memo[i][j] = cnt;
}
void solve() {
    int n; cin >> n;
    int ans = dfs(0, n);
    cout << ans << nl;
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
