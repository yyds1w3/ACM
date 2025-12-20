// 1. 暴力O(N^2)超时
// 2. 分解因子O(N根号N)
// 3. 调和级数筛O(NlogN)
#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MAXN = 1e5 + 1;
const int MAXA = 1e6 + 1;
int cnt[MAXA];
ll ans[MAXA];
int a[MAXN];
void solve() {
    int n, max_v = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
        max_v = max(max_v, a[i]);
    }
    for (int i = 1; i <= max_v; ++i){
        if (cnt[i] == 0) continue;
        for (int j = i; j <= max_v; j += i){
            ans[j] += cnt[i];
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << ans[a[i]] - 1 << endl;
    }
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
