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
const int MAXN = 2e5 + 1;
int a[MAXN];
void solve() {
    int n, w; cin >> n >> w;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) cin >> a[i];
    int tot_blo = 1 + (n-1) / (w * 2);
    ll ans;
    ll temp = 0;
    int base_l = 0, base_r = w-1;
    for (int blo = 0; blo < tot_blo; ++blo) {
        int offset = blo * w * 2;
        int l = min(base_l + offset, n + 1);
        int r = min(base_r + offset, n + 1);
        for (int i = l; i <= r; ++i) temp += a[i];
    }
    ans = temp;
    for (int x = 1; x < 2*w; ++x) {
        for (int blo = 0; blo < tot_blo; ++blo) {
            int offset = blo * 2 * w;
            int l = min(((base_l + x) % (2*w)) + offset, n + 1);
            int r = min(((base_r + x) % (2*w)) + offset, n + 1);
            temp += a[r] - a[(l+2*w-1)%(2*w) + offset];
        }
        ans = min(ans, temp);
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
    cin >> tt;
    while (tt--) solve();
}
