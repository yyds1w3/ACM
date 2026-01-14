#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
int dp[MAXN];
void solve() {
    string s; cin >> s;
    size_t sz = s.size();
    int mx = 0;
    int cnt = 1;
    for (size_t i = 1; i < sz; ++i) {
        if (s[i] == ')') {
            int pre_idx = i - 1 - dp[i-1];
            if (pre_idx >= 0 && s[pre_idx] == '(') {
                dp[i] = dp[i-1] + 2 + (pre_idx >= 1 ? dp[pre_idx-1] : 0);
            }
        }
        if (dp[i] > mx) {
            mx = dp[i];
            cnt = 1;
        }else if (dp[i] == mx && mx > 0) {
            cnt++;
        }
    }
    cout << mx << " " << cnt << nl;

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
