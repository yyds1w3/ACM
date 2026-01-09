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
const int MAXN = 3e5 + 1;
int a[MAXN], t[MAXN];
void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    memset(t, 0x3f, sizeof(t));
    for (int i = 1; i <= k; ++i) {
        cin >> t[a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        t[i] = min(t[i], t[i-1] + 1);
    }
    for (int i = n-1; i >= 1; --i) {
        t[i] = min(t[i], t[i+1] + 1);
    }
    for (int i = 1; i <= n; ++i) cout << t[i] << " ";
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
