#include <bits/stdc++.h>
#include <functional>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e4 + 5;
int H[MAXN];
void solve() {
    int N, B; cin >> N >> B;
    rep(i, 1, N) cin >> H[i];
    sort(H + 1, H + 1 + N, greater<int>());
    ll sum = 0;
    ll num = 0;
    rep(i, 1, N) {
        sum += H[i];
        num++;
        if (sum >= B) break;
    }
    cout << num << nl;
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
