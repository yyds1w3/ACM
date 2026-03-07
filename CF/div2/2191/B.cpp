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
const int MAXN = 1e2 + 5;
void solve() {
    int n; cin >> n;
    int n0 = 0, n1 = 0;
    rep(i, 1, n) {
        int x; cin >> x;
        if (x == 0) n0++;
        if (x == 1) n1++;
    }
    if (n0 == 0) cout << "NO" << nl; // 
    else if (n1 == 0) { // 
        if (n0 >= 2) cout << "NO" << nl; // 0 ..... 0
        else cout << "YES" << nl; 
    }else cout << "YES" << nl; // n0 != 0, n1 != 0, 0 ........ 1; // 1 != 0
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
