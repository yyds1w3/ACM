#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (ll)e; ++i)
#define per(i,e,s) for (ll i = e; i >= (ll)s; --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
char a[MAXN][MAXN];
int dp[MAXN];
int stk[MAXN], top;
void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    ll ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if (a[i][j] == '.') dp[j]++;
            else dp[j] = 0;
        }
        rep(j, 1, m){
            if (top != 0 && dp[stk[top]] < dp[j]) {
                stk[++top] = j;
            }
            while (top != 0 && dp[stk[top] > dp[j]]) {
                --top;
            }
            ans += 
        }

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
