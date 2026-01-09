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

void solve() {
    int n, k; cin >> n >> k;
    int kk = n - (k - 3);
    for (int i = 1; i <= k - 3; ++i) cout << 1 << " ";
    if (kk & 1) cout << 1 << " " << kk / 2 << " " << kk / 2;
    else if (kk % 4 == 0) cout << kk / 2 << " " << kk / 4 << " " << kk / 4; 
    else cout << kk / 2 - 1 << " " << kk / 2 - 1 << " " << 2;
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
