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
const int INF = 0x3f3f3f3f;
const int MAXN = 8e5 + 10;
const int OFF = 4e5;
ll dp[MAXN];
void solve() {
    int n;
    cin >> n;
    fill(dp, dp + MAXN, -INF);
    dp[OFF] = 0;
    for (int i = 0; i < n; ++i){
        int s, f;
        cin >> s >> f;
        if (s >= 0){
            for (int j = MAXN - 1; j >= s; --j){// s, MAXN
                if (dp[j - s] != -INF)
                dp[j] = max(dp[j], dp[j - s] + f);
            }
        }else{
            for (int j = 0; j <= MAXN - 1 + s; ++j){ // 0 MAXN - 1 - (-s)
                if (dp[j - s] != -INF)
                dp[j] = max(dp[j], dp[j - s] + f);
            }
        }
    }
    ll ans = 0;
    for (int i = OFF; i <= MAXN - 1; ++i){
        if (dp[i] >= 0){
            ans = max(ans, dp[i] + i - OFF);
        }
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
