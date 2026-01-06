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
    int n; cin >> n;
    int z = 0;
    map<int,int> m;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        m[x]++;
        z = max(z, m[x]);
    }
    if (2 * z > n) cout << (2 * z - n) << "\n";
    else cout << (n % 2) << "\n";
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
