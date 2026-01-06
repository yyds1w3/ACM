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
const int MAXN = 1e6 + 1;
int a[MAXN];
void solve() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c; 
        if (c == '*') {
            a[++cnt] = i;
        }
    }
    if (cnt == 0) {cout << "0\n"; return;}
    ll ans = 0;
    int mid = (cnt + 1) / 2;
    for (int i = 1; i <= cnt; ++i) {
        ans += abs(a[i] - a[mid] - (i - mid));
    }
    cout << ans << "\n";
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
