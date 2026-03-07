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
const int MAXN = 1e5 + 5;
void solve() {
    string s; cin >> s;
    int n = s.size();
    int mx = 0;
    rep(i, 0, 9) {
        rep(j, 0, 9) {
            int ans = 0;
            int f = 0;
            rep(k, 0, n-1) {
                if (f == 0 && s[k] == i + '0') {f = 1; ans++;}
                else if (f == 1 && s[k] == j + '0') {f = 0; ans++;}
            }
            if (i != j && f == 1) ans--;
            mx = max(mx, ans);
        }
    }
    cout << n - mx << nl;
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
