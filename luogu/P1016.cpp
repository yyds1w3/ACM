#include <bits/stdc++.h>
#include <iomanip>
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
const int MAXN = 10;
double d[MAXN], p[MAXN];
void solve() {
    double s, c, l, p0; int n; cin >> s >> c >> l >> p0 >> n;
    rep(i, 1, n) cin >> d[i] >> p[i];
    d[0] = 0; p[0] = p0; d[n+1] = s; p[n+1] = 0;
    double mx_run = c*l;
    rep(i, 0, n) {
        if (d[i+1]-d[i] > mx_run) {
            cout << "No Solution" << nl;
            return;
        }
    }
    int now = 0;
    double gas = 0;
    double cost = 0;
    while (now < n+1) {
        bool f = false;
        double need;
        double add;
        double mn_price = 1e9;
        int mn_station = -1;
        rep(i, now+1, n+1) {
            if (d[i]-d[now] > mx_run) break;
            if (p[i] < p[now]) {
                need = (d[i] - d[now]) / l;
                add = max(double(0), need - gas);
                gas += add - need;
                cost += add*p[now];
                now = i;
                f = true;
                break;
            }
            if (p[i] < mn_price) {
                mn_station = i;
                mn_price = p[i];
            }
        }
        if (!f) {
            need = (d[mn_station] - d[now]) / l;
            add = c-gas;
            gas += add - need;
            cost += add*p[now];
            now = mn_station;
        }
    }
    cout << setprecision(2) << fixed << cost << nl;
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
