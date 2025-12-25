#include <bits/stdc++.h>
#include <functional>
#include <iomanip>
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
double a[MAXN], b[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + 1 + n, greater<double>());
    sort(b + 1, b + 1 + n, greater<double>());

    int l = 0, r = 0;
    double pa = 0, pb = 0;
    double ans = 0;
    while (l < n || r < n){
        if (r == n || (l < n && pa < pb)){
            l++;
            pa += a[l];
        }else{
            r++;
            pb += b[r];
        }
        ans = max(min(pa, pb) - l - r, ans);
    }
    cout << setprecision(4) << fixed <<  ans;
    
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
