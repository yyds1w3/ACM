#include <bits/stdc++.h>
#include <stack>
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

int n, m;
const int MAXN = 1e3 + 1;
ll dp[MAXN];
stack<int> stk;
ll ans = 0;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1;j <= m; ++j){
            char c;
            cin >> c;
            if (c == 'R') dp[j] = 0;
            else dp[j] += 1;
        }
        for (int j = 1; j <= m; ++j){
            while (!stk.empty() && dp[j] < dp[stk.top()]){
                ll h = dp[stk.top()];
                stk.pop();
                int l = stk.empty() ? 0 : stk.top();
                int r = j;
                ans = max(ans, (r - 1 - l) * h);
            }
            stk.push(j);
        }
        while (!stk.empty()){
            ans = max(ans, (m + 1 - stk.top()) * dp[stk.top()]);
            stk.pop();
        }
    }
    cout << 3 * ans;
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
