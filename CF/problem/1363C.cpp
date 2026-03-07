#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 5;
void solve() {
    int n, k; cin >> n >> k;
    int deg = 0;
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        if (u == k || v == k) deg++; 
    }
    if (deg <= 1) {
        cout << "Ayush" << nl;
    }else {
        cout << (!(n&1) ? "Ayush" : "Ashish") << nl;
    }
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
