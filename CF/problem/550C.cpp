#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i, s, e) for (int i = s; i <= e; ++i)
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
    string s; cin >> s;
    int n = s.size();
    rep(i, 0, n-1) {
        int num = s[i]-'0';
        if (num % 8 == 0) {
            cout << "YES" << nl;
            cout << num << nl;
            return;
        }
    }
    rep(i, 0, n-1) rep(j, i+1, n-1) {
        int num1 = 10 * (s[i] - '0');
        int num2 = s[j] - '0';
        if ((num1 + num2) % 8 == 0) {
            cout << "YES" << nl;
            cout << num1 + num2 << nl;
            return;
        }
    }
    rep(i, 0, n-1) rep(j, i+1, n-1) rep(k, j+1, n-1) {
        int num1 = 100 * (s[i] - '0');
        int num2 = 10 * (s[j] - '0');
        int num3 = s[k] - '0';
        if ((num1 + num2 + num3) % 8 == 0) {
            cout << "YES" << nl;
            cout << num1 + num2 + num3 << nl;
            return;
        }
    }
    cout << "NO" << nl;
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
