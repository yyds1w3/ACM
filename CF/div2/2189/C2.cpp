#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
#define repp(i,e,s) for (int i = e; i >= s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
int a[MAXN];
void solve() {
    int n; cin >> n;
    a[n] = 3;
    int lst = n;
    bool f = true;
    repp(i, n-1, 1) {
        a[i] = a[lst] ^ i;
        if (a[i] == 0) f = false;
        if (a[i] > a[lst]) lst = i;
    }
    if (f) {rep(i, 1, n) cout << a[i] << " "; cout << nl;}
    else cout << "-1" << nl;
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
