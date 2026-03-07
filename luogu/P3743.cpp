#include <bits/stdc++.h>
#include <iomanip>
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
const int MAXN = 1e5 + 5;
int n;
double p;
double a[MAXN], b[MAXN];
bool check(double time) {
    double need = 0;
    double has = p * time;
    rep(i, 1, n) {
        if (a[i] * time > b[i]) {
            need += a[i] * time - b[i];
        }
    }
    return need <= has;
}
void solve() {
    cin >> n >> p;
    double sum_a = 0;
    rep(i, 1, n) {
        cin >> a[i] >> b[i];
        sum_a += a[i];
    }
    if (p >= sum_a) {
        cout << -1 << nl;
        return;
    }
    double l = 0, r = 1e10;
    rep(i, 1, 100) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << l << nl;
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
