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
const int MAXN = 51;
int a[MAXN];
void solve() {
    int n; cin >> n;
    ll sum_odd = 0, sum_even = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i & 1) sum_odd += a[i];
        else sum_even += a[i];
    }
    if (sum_odd > sum_even) {
        for (int i = 1; i <= n; ++i) {
            if (i & 1) cout << a[i] << " ";
            else cout << 1 << " ";
        }
    }else {
        for (int i = 1; i <= n; ++i) {
            if (i & 1) cout << 1 << " ";
            else cout << a[i] << " ";
        }
    }
    cout << "\n";
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
