#include <bits/stdc++.h>
#include <numeric>
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
const int MAXN = 5e5 + 1;
void solve() {
    int n; cin >> n;
    int preD = 0, preK = 0;
    map<pair<int, int>, int> m;
    for (int i = 1; i <= n; ++i) {
        char c; cin >> c;
        if (c == 'D') {
            preD++;
        }else {
            preK++;
        }
        int g = gcd(preD, preK);
        pair<int, int> now = {preD/g, preK/g};
        m[now]++;
        cout << m[now] << " ";
    }
    cout << endl;
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
