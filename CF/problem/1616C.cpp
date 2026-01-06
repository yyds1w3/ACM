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
int a[201];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n <= 2) {
        cout << "0\n";
        return;
    }
    int mx = 1;
    for (int i = 1; i <= n; ++i) {
        map<pair<int, int>, int> ma;
        for (int j = i + 1; j <= n; ++j) {
            int diff = a[j] - a[i];
            int dis = j - i;
            int g = gcd(abs(diff), abs(dis));
            ma[{diff / g, dis / g}]++;
            mx = max(ma[{diff / g, dis / g}] + 1, mx);
        }
    }
    cout << n - mx << "\n";
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
