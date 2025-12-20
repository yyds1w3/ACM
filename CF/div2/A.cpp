#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using i64 = long long;
using ui64 = unsigned long long;
using ui32 = unsigned int;
using i128 = __int128;

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    int mx = 0;
    for (int x = a; x <= a + b * l; x += b){
        mx = max(mx, x % l);
    }
    cout << mx << endl;
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
