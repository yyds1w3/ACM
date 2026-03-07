#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (ll)e; ++i)
#define per(i,e,s) for (ll i = e; i >= (ll)s; --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 5e2 + 5;
ll N[MAXN][MAXN];
int R, C, A, B;
bool check(ll x) {
    int now_a = 0;
    int lst_a = 0;
    rep(i, 1, R) {
        int now_b = 0;
        int lst_b = 0;
        rep(j, 1, C) {
            if (N[i][j] + N[lst_a][lst_b] - N[i][lst_b] - N[lst_a][j] >= x) {
                now_b++;
                lst_b = j;
            }
        }
        if (now_b >= B) {
            now_a++;
            lst_a = i;
        }
        if (now_a >= A) return true;
    }
    return now_a >= A;

}
void solve() {
    cin >> R >> C >> A >> B;
    rep(i,1,R) rep(j,1,C) cin >> N[i][j];
    rep(i,1,R) rep(j,1,C) N[i][j] += N[i-1][j] + N[i][j-1] - N[i-1][j-1];
    ll l = 0, r = N[R][C];
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << l << nl;
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
