#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
string s[2];
void solve() {
    cin >> s[0] >> s[1];
    int n = s[0].size();
    int l = -1;
    int ans = 0;
    rep(j, 0, n-1) {
        if (s[0][j] == '#' || s[1][j] == '#') {
            if ((s[0][j] == '#' && s[0][l] == '#') || (s[1][j] == '#' && s[1][l] == '#')) {
                if (l == -1) {l = j; continue;}
                ans += j - l - 1;
            }else {
                if (l == -1) {l = j; continue;} 
                ans += j - l;
                s[0][j] = s[1][j] = '#';
            }
            l = j;
        }
    }
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
