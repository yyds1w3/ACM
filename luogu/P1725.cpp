// i <== [i - r, i - l], 我们维护一个单调队列
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
const int INF = 0x3f3f3f3f;
int n, l, r;
int dp[MAXN], a[MAXN], q[MAXN];
void solve() {
    cin >> n >> l >> r;
    for (int i = 0; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= n; ++i) dp[i] = -INF;
    dp[0] = 0;
    int head = 1, tail = 0;
    int ans = -INF;

    for (int i = l; i <= n; ++i){
        int k = i - l;
        if (dp[k] != -INF){
            while (head <= tail && dp[q[tail]] <= dp[k]) tail--;
            q[++tail] = k;
        }
        if (head <= tail && i - q[head] > r) ++head;
        if (head <= tail) dp[i] = dp[q[head]] + a[i];
        if (i + r > n) ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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
