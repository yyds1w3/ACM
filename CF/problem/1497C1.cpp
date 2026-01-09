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
    if (n & 1) cout << 1 << " " << n / 2 << " " << n / 2;
    else if (n % 4 == 0) cout << n / 2 << " " << n / 4 << " " << n / 4;
    else cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2;
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
