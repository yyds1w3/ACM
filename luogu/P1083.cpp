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
const int MAXN = 1e6 + 1;
int a[MAXN];
ll diff[MAXN];
struct dingdan{
    int d, s, t;
}dd[MAXN];
int n, m, d, s, t;
bool check(int x){
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= x; ++i){
        diff[dd[i].s] += dd[i].d;
        diff[dd[i].t + 1] -= dd[i].d;
    }
    for (int i = 1; i <= n; ++i){
        diff[i] += diff[i-1];
        if (diff[i] > a[i]){
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> dd[i].d >> dd[i].s >> dd[i].t;
    }
    int l = 0, r = m + 1;
    while (l < r){
        int mid = (l + r) / 2;
        if (!check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if (r == m + 1) cout << 0 << endl;
    else cout << "-1\n" << r << endl;
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
