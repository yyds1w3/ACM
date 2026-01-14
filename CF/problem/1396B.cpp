#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 101;
ll a[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll mx = *max_element(a + 1, a + 1 + n);
    ll tot = accumulate(a + 1, a + 1 + n, 0ll);
    if (mx * 2 > tot || (tot & 1)) cout << "T" << nl;
    else cout << "HL" << nl;
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
