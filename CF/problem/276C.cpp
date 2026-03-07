#include <bits/stdc++.h>
#include <numeric>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
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
const int MAXN = 2e5 + 5;
int a[MAXN];
int diff[MAXN];
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        int l, r; cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }
    for (int i = 1; i <= n; ++i) diff[i] += diff[i-1];
    sort(a+1, a+1+n);
    sort(diff + 1, diff + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans += ll(a[i]) * diff[i];
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
