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
const int MAXN = 5001;
ll a[MAXN], b[MAXN];
ll sum;
ll ans;
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) sum += a[i] * b[i];
    for (int i = 1; i <= n; ++i) {
        int l, r;
        l = r = i;
        ll curr_sum = sum;
        while (l >= 1 && r <= n) {
            curr_sum += a[r]*b[l]+a[l]*b[r]-a[r]*b[r]-a[l]*b[l];
            ans = max(ans, curr_sum);
            l--;
            r++;
        }
        l = i, r = i + 1;
        curr_sum = sum;
        while (l >= 1 && r <= n) {
            curr_sum += a[r]*b[l]+a[l]*b[r]-a[r]*b[r]-a[l]*b[l];
            ans = max(ans, curr_sum);
            l--;
            r++;
        }
    }
    cout << ans << endl;
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
