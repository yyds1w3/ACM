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
const int MAXN = 55;
char m[MAXN][MAXN];
int pre[MAXN], mid[MAXN], suff[MAXN];
int col[MAXN][3];
void solve() {
    int N, M; cin >> N >> M;
    rep(i, 1, N) rep(j, 1, M) {
        cin >> m[i][j];
        if (m[i][j] == 'W') col[i][0]++;
        else if (m[i][j] == 'B') col[i][1]++;
        else col[i][2]++;
    }
    rep(i, 1, N-2) pre[i] = pre[i-1] + M - col[i][0];
    rep(i, 2, N-1) mid[i] = mid[i-1] + M - col[i][1];
    per(i, N, 3) suff[i]= suff[i+1] + M - col[i][2];
    int mn = INF;
    rep(i, 1, N-2) {
        rep(j, i+1, N-1) {
            mn = min(mn, pre[i] + mid[j] - mid[i] + suff[j+1]);
        }
    }
    cout << mn << nl;
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
