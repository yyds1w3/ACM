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
const int MAXN = 2e3 + 1;
int a[MAXN];
void solve() {
    int n; cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tot ^= a[i];
    }
    if (tot == 0) {
        cout << "YES\n";
        return;
    }
    int cnt = 0;
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        t ^= a[i];
        if (t == tot) {
            t = 0;
            cnt++;
        }
    }
    if (cnt >= 3) cout << "YES\n";
    else cout << "NO\n";
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
