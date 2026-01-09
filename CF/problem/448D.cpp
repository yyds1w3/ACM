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
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
ll n, m, k;
bool check(ll x) {
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (x < i) break;
        sum += min(x / i, m);
    }
    if (sum < k) return true;
    return false;
}
void solve() {
    cin >> n >> m >> k;
    ll l = 0, r = n * m;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) { // < k
            l = mid + 1;
        }else {
            r = mid;
        }
    }
    cout << l << endl;
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
