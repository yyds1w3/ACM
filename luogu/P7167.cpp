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
const int MAXL = 20;
int n, q, stk[MAXN], top, nxt[MAXN];
int f[MAXN][MAXL];
int sum[MAXN][MAXL];
struct st{
    int d, c;
}a[MAXN];
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].d >> a[i].c;
        while (top && a[stk[top]].d < a[i].d){
            nxt[stk[top--]] = i;
        }
        stk[++top] = i;
    }
    for (int i = 1; i <= n; ++i) {
        f[i][0] = nxt[i];
        sum[i][0] = a[i].c;
    }
    for (int k = 1; k <= 17; ++k) {
        for (int i = 1; i <= n; ++i) {
            f[i][k] = f[f[i][k-1]][k-1];
            sum[i][k] = sum[i][k-1] + sum[f[i][k-1]][k-1];
        }
    }
    for (int i = 1; i <= q; ++i) {
        int r, v;
        cin >> r >> v;
        int now = r;
        for (int k = 17; k >= 0; --k){
            if (f[now][k] > 0 && v > sum[now][k]) {
                v -= sum[now][k];
                now = f[now][k];
            }
        }
        if (v > a[now].c) cout << 0 << "\n";
        else cout << now << "\n";
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
