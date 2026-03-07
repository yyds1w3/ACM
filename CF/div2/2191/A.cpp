#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
struct st {
    int id, val;
    bool operator<(const st& other) {return val < other.val;}
}a[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a+1, a+1+n);
    rep(i, 1, n-1) {
        if ((a[i].id & 1) == (a[i+1].id & 1)) {cout << "NO" << nl;return;}
    }
    cout << "YES" << nl;

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
