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
const int MAXN = 2e5 + 1;
int va[MAXN], vb[MAXN];
int cntA[MAXN];
int cntB[MAXN];
void solve() {
    int a, b, k; cin >> a >> b >> k;
    for (int i = 1; i <= a; ++i) cntA[i] = 0;
    for (int i = 1; i <= b; ++i) cntB[i] = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> va[i];
        cntA[va[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
        cin >> vb[i];
        cntB[vb[i]]++;
    }
    ll ans = 0;
    int end = k;
    for (int i = 1; i <= end; ++i) {
        ans += (k - 1) - (cntA[va[i]] - 1) - (cntB[vb[i]] - 1);
        k--;
        cntA[va[i]]--;
        cntB[vb[i]]--;
    }
    cout << ans<< endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
