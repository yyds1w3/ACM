// dp无后效性，最优子结构
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(x) 42
#endif
const int N = 1e5 + 1;
ll cnt[N];
ll dp[N];
void solve() {
    int n;
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }
    dp[1] = cnt[1] * 1;
    for (int i = 2; i <= mx; ++i){
        dp[i] = max(dp[i-1], dp[i-2] + cnt[i] * (ll)i);
    }
    cout << dp[mx] << '\n';
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
