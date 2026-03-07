#include <bits/stdc++.h>
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
const int MAXN = 2e3 + 5;
bool check(int x, int a0, int a1, int b0, int b1) {
    if (gcd(x, a0) != a1) return false;
    if ((1LL * x * b0) / gcd(x, b0) != b1) return false;
    return true;
}
void solve() {
    int n; cin >> n;
    rep(i, 1, n) {
        int a0, a1, b0, b1; cin >> a0 >> a1 >> b0 >> b1;
        int cnt = 0;
        for (int x = 1; x * x <= b1; ++x) {
            if (b1 % x == 0) {
                if (check(x, a0, a1, b0, b1)) cnt++;
                if (x * x != b1) {
                    if (check(b1 / x, a0, a1, b0, b1)) cnt++;
                }
            }
        } 
        cout << cnt << nl;
    }

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
