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
struct st {
    int val, id;
    bool operator<(const st& other) const {return val < other.val;}
}a[MAXN];
int b[MAXN];
void solve() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].val;
        a[i].id = i;
        if (a[i].val == 0) cnt++;
    }
    if (cnt >= 2) cout << -1 << nl;
    else {
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; ++i) b[a[i].id] = i;
        for (int i = 1; i <= n; ++i) {
            cout << b[i] << " ";
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
