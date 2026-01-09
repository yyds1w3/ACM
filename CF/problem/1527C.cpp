#include <bits/stdc++.h>
#include <unordered_map>
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
const int MAXN = 1e5 + 1;
void solve() {
    int n; cin >> n;
    unordered_map<int, ll> m;
    ll ans = 0;
    // 每一对的(i, j)贡献 i * (n - j + 1)
    for (int j = 1; j <= n; ++j) {
        int x; cin >> x;
        if (m.count(x)) { // 如果可以形成一对
            ans += m[x] * (n - j + 1); // m[x] 代表i之和
        }
        m[x] += j;
    }
    cout << ans << endl;
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
