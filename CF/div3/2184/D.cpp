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
const int MAXN = 1e5 + 5;
ll comb[65][65];
void init() {
    comb[0][0] = 1;
    for (int i = 1; i <= 64; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
}
void solve() {
    ll n, k; cin >> n >> k;
    ll d = 0;
    while (n >>= 1) d++; // 2 --> d == 1
    ll ans = 0;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i + 1 + j > k) ans += comb[i][j];
        } 
    }
    if (d + 1 > k) ans++;
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
    init();
    while (tt--) solve();
}
