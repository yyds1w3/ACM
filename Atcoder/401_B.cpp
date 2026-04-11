#include <bits/stdc++.h>
#include <cmath>
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

void solve() {
    bool loged = false;
    int n; cin >> n;
    int ans = 0;
    rep(i, 1, n) {
        string s; cin >> s;
        if (s == "login") {
            loged = true;
        }else if (s == "logout") {
            loged = false;
        }else if (s == "private") {   
            if (loged == false) ans++; 
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
