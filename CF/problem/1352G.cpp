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
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

void solve() {
    int n; cin >> n;
    if (n < 4) cout << "-1" << nl;
    else {
        if (n & 1) {
            for (int i = n - 1; i >= 6; i -= 2) cout << i << " ";
            cout << "2 4 ";
            for (int i = 1; i <= n; i += 2) cout << i << " ";
        }else {
            for (int i = n; i >= 6; i -= 2) cout << i << " ";
            cout << "2 4 ";
            for (int i = 1; i <= n - 1; i += 2) cout << i << " ";
        }
        cout << nl;
    }
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
