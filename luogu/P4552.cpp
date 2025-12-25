#include <bits/stdc++.h>
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
ll a[MAXN];
ll diff[MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        diff[i] = a[i] - a[i-1];
    }
    ll p = 0, q = 0;
    for (int i = 2; i <= n; ++i){
        if (diff[i] > 0) 
            p += diff[i];
        else
            q -= diff[i];
    }
    cout << max(p, q) << endl << abs(p - q) + 1 << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
