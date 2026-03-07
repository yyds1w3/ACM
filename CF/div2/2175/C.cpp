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
const int MAXN = 1e5 + 5;
int cnts[26];
int cntt[26];
void solve() {
    string s, t; cin >> s >> t;
    rep(i, 0, 25) cnts[i] = cntt[i] = 0;
    rep(i, 0, s.size()-1) cnts[s[i]-'a']++;
    rep(i, 0, t.size()-1) cntt[t[i]-'a']++;
    rep(i, 0, 25) {
        if (cntt[i] < cnts[i]) {
            cout << "Impossible" << nl;
            return;
        }
        cntt[i] -= cnts[i];
    }
    int now = 0;
    string ans = "";
    rep(i, 0, s.size() - 1) {
        int cur = s[i] - 'a';
        while (now < cur) {
            ans += string(cntt[now], now+'a');
            now++;
        }
        ans += s[i];
    }
    rep(i, now, 25) ans += string(cntt[i], i+'a');
    cout << ans << nl;
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
