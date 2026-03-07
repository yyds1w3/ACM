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
const int MAXN = 3e6 + 5;
int a[MAXN];
int st[MAXN], top;
int ans[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        while (top > 0 && a[i] > a[st[top]]) { // 维护一个单调递减的栈
            ans[st[top]] = i;
            top--;
        }
        st[++top] = i;
    }
    while (top) {ans[st[top]] = 0; top--;}
    rep(i, 1, n) cout << ans[i] << " ";
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
