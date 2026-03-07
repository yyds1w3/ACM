#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= ll(e); ++i)
#define per(i,e,s) for (ll i = e; i >= ll(s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
int a[MAXN];
int cnt[MAXN];
int ans[MAXN];
void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, n) {cin >> a[i]; if (a[i] <= 1e6) cnt[a[i]]++;}
    rep(i, 1, m) {
        if (cnt[i] > 0) {
            for (int j = i; j <= m; j += i) ans[j] += cnt[i];
        }
    }
    int lcm = 1;
    rep(i, 1, m) {
        if (ans[lcm] < ans[i]) lcm = i; 
    }
    cout << lcm << " " << ans[lcm] << nl;
    rep(i, 1, n) if (lcm % a[i] == 0) cout << i << " ";
    cout << nl;
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
