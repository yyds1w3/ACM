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
const int MAXN = 2e5 + 5;
ll odd[MAXN];
ll even[MAXN];
void solve() {
    int n; cin >> n;
    int tot1 = 0, tot2 = 0;
    for (int i = 1; i <= n; ++i) {
        int x;cin >> x;
        if (x & 1) odd[++tot1] = x;
        else even[++tot2] = x;
    }
    sort(odd + 1, odd + 1 + tot1, greater<ll>());
    sort(even+ 1, even+ 1 + tot2, greater<ll>());
    for (int i = 1; i <= tot2; ++i) even[i] += even[i-1];
    if (tot1 == 0) {
        rep(i, 1, n) cout << 0 << " ";
        cout << nl;
        return;
    }
    for (int k = 1; k <= n; ++k) {
        int q = min(k-1, tot2);
        int p = k-q;
        if (p % 2 == 0) {
            q--;
            p++;
        }
        if (q < 0 || p > tot1) cout << 0 << " ";
        else cout << odd[1] + even[q] << " ";
    }
    cout << nl;
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
