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
struct st {
    int val, id;
    bool operator<(const st& other ) const {return val < other.val;}
}a[33];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {cin >> a[i].val; a[i].id = i;}
    sort(a + 1, a+ 1 + n);
    cout << a[1].id << " "<<a[2].id<<" " << a[3].id;
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
