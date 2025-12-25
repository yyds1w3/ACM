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
ll ans;
stack<int> stk;
void solve() {
    int n, h;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> h;
        while (!stk.empty() && stk.top() <= h)
            stk.pop();
        ans += stk.size();
        stk.push(h);
    }
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
