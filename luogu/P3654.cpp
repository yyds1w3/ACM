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
const int MOD = 1e9 + 7;
const int MAXN = 1e2 + 5;
char a[MAXN][MAXN];
void solve() {
    int R, C, K; cin >> R >> C >> K;
    rep(i, 1, R) {
        rep(j, 1, C) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    rep(i, 1, R) {
        rep(j, 1, C) {
            int rm = 0,cm = 0;
            if (i+K-1 <= R){cm = 1;rep(k, 0, K-1) if (a[i+k][j] == '#') {cm--;break;}}
            if (j+K-1 <= C){rm = 1;rep(k, 0, K-1) if (a[i][j+k] == '#') {rm--;break;}}
            sum += rm + cm;
        }
    }
    if (K == 1) sum /= 2;
    cout << sum << nl;
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
