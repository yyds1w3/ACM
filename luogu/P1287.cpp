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
#define rep(i,s,e) for (ll i = s; i <= ll(e); ++i)
#define per(i,e,s) for (ll i = e; i >= ll(s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
ll s[15][15]; // n 个不同球 r个不同的盒子
// s(n, r) == s(n-1, r-1) + r * s(n-1, r)
void solve() {
    int n, r; cin >> n >> r;
    s[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= r; ++j) {
            s[i][j] = s[i-1][j-1] + j * s[i-1][j];
        }
    }
    rep(i, 1, r) s[n][r] *= i;
    cout << s[n][r] << nl;
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
