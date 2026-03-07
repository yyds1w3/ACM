#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctz(x)
#define ctzll(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(x)
#define clzll(x) __builtin_clzll(x)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
int lg2(int x) {return 31 - clz(x);}
int lg2(ll x) {return 63 - clzll(x);}
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = s + s;
    int mx = 0;
    int cnt = 0;
    for (int i = 1; i <= 2 * n - 1; ++i) {
        if (s[i] == '0' && s[i-1] == '0') {
            cnt++;
            mx = max(mx, cnt);
        }else if (s[i] == '0' && s[i-1] == '1') {
            cnt = 1;
            mx = max(mx, cnt);
        }else cnt = 0;
    }
    cout << mx << nl;
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
