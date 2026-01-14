#include <bits/stdc++.h>
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
const int MAXN = 2e5 + 5;
ll a[MAXN];
void solve() {
    int n, m; cin >> n >> m;
    ll b;
    cin >> a[1];
    for (int i = 2; i <= n; ++i){
        cin >> a[i];
        a[i] -= a[1];
    }
    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = gcd(ans, a[i]);
    }
    for (int j = 1; j <= m; ++j) {
        cin >> b;
        cout << gcd(ans, a[1]+b) << " ";
    }
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
