#include <bits/stdc++.h>
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
const int MAXN = 1e5 + 5;
struct tree {
    ll x, h;
    bool operator<(const tree& other) {return x < other.x;}
}a[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].h;
    a[n].x = LINF;
    sort(a, a + n);
    ll ans = 1, occ = a[0].x;
    for (int i = 1; i < n; ++i) {
        if (a[i].x - a[i].h > occ) {
            ans++;
            occ = a[i].x;
        }else if (a[i].x + a[i].h < a[i+1].x){
            occ = a[i].x + a[i].h;
            ans++;
        }else occ = a[i].x;
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
