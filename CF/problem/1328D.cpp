#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (count(a.begin(), a.end(), a[0]) == n) {
        cout << 1 << "\n";
        for (int i = 0; i < n; ++i) cout << "1 ";
        cout << "\n";
        return;
    }

    if (n % 2 == 0) {
        cout << 2 << "\n";
        int j = 1;
        for (int i = 0; i < n; ++i) cout << (j ^= 1) + 1 << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        int nxt = (i + 1) % n;
        if (a[i] == a[nxt]) {
            vector<int> ans(n);
            for (int k = i, j = 0; k >= 0; --k, j ^= 1) {
                ans[k] = j + 1;
            }
            for (int k = i + 1, j = 0; k < n; ++k, j ^= 1) {
                ans[k] = j + 1;
            }

            cout << 2 << "\n";
            for (int v : ans) cout << v << " ";
            cout << "\n";
            return;
        }
    }
    cout << 3 << "\n";
    int j = 0;
    for (int i = 0; i < n - 1; ++i) cout << (j ^= 1) + 1 << " ";
    cout << 3 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
