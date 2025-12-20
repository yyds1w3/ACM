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
bool memo[30][300];
bool f[300];
int ans;
void dfs(int n, int m){
    if (memo[n][m]) return;
    memo[n][m] = true;
    if (n == 0){
        if (!f[m]) ans++;
        f[m] = true;
        return;
    }
    for (int r = n; r >= 1; --r) dfs(n - r, r * (n-r) + m);
}
void solve() {
    int n;
    cin >> n;
    dfs(n,0);
    cout << ans;
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
