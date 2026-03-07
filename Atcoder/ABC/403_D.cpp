#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXN = 1e6 + 1;
int cnt[MAXN];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N, D; cin >> N >> D;
    int mx = 0;
    for (int i = 1; i <= N; ++i) {
        int x; cin >> x;
        cnt[x] += 1;
        mx = max(mx, x);
    }
    if (D == 0) {
        ll ans = 0;
        for (int i = 0; i <= mx; ++i) {
            ans += max(0, cnt[i] - 1);
        }
        cout << ans << nl;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < D; ++i) {
        int dp0 = 0, dp1 = 0; // 0 删 1 不删
        for (int j = i; j <= mx; j += D) {
            int nxdp0 = min(dp0 + cnt[j], dp1 + cnt[j]);
            int nxdp1 = dp0;
            dp0 = nxdp0, dp1 = nxdp1;
        }
        ans += min(dp0, dp1); 
    }
    cout << ans << nl;
}
