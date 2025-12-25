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
int a[MAXN];
void solve() {
    int n, mx = -2e9;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = max(a[i], a[i-1] + a[i]);
        mx = max(a[i], mx);
    }
    cout << mx;


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
