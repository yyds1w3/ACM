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
const int MAXN = 3e5 + 5;
int a[MAXN], cnt;
bool exist[MAXN];
int dp[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) {
        dp[i] = INF;
        exist[i] = false;
        cnt = 0;
    }
    rep(i, 1, n) {
        int x; cin >> x;
        if (!exist[x]) {
            exist[x] = true;
            a[++cnt] = x;
        }
    }
    rep(i, 1, cnt) dp[a[i]] = 1;
    rep(i, 1, cnt) {
        if (a[i] == 1) continue;
        for (int j = 1; j * a[i] <= n; ++j) {
            if (dp[j] != INF) dp[j*a[i]] = min(dp[j*a[i]], dp[j]+1);
        }
    }
    rep(i, 1, n) cout << (dp[i] == INF ? -1 : dp[i]) << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
