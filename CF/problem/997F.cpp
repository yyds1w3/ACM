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
const int MAXN = 2e5 + 1;
int a[MAXN];
void solve() {
    int n; cin >> n;
    map<int, int> m;
    int ans = 0;
    int lst = 0;
    for (int i = 1; i<= n; ++i) {
        cin >> a[i];
        m[a[i]] = m[a[i]-1] + 1;
        if (ans < m[a[i]]) {
            ans = m[a[i]];
            lst = a[i];
        }
    }
    cout << ans << nl;
    int val = lst - ans + 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == val) {
            cout << i << " ";
            val++;
        }
    }
    cout << nl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
