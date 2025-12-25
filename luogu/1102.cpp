#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
const int MAXN = 2e5 + 5;
map<ll, ll> mp;
int a[MAXN];
void solve() {
    ll n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        ans += mp[a[i] - c];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
