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

const int MAXN = 2e5 + 1;
ll a[MAXN], b[MAXN];
int n;
bool check(int x) {
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    for (int i = n; i >= 3; --i) {
        if (b[i] < x) return false;
        b[i-1] += min(b[i] - x, a[i]) / 3;
        b[i-2] += min(b[i] - x, a[i]) / 3 * 2;
    }
    if (b[1] < x || b[2] < x) return false;
    return true;
}
void solve() {
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int l = 0, r = mx;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
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
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
