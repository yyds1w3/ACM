#include <algorithm>
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
const int MAXN = 1e5 + 5;
int cb, cs, cc;
int nb, ns, nc; 
int pb, ps, pc; 
ll money; 
bool check(ll x) {
    ll need = pb * max(cb * x - nb, 0ll) + ps * max(cs * x - ns, 0ll) + pc * max(cc * x - nc, 0ll);
    return money >= need;
}
void solve() {
    string recipe; cin >> recipe;
    cb = count(recipe.begin(), recipe.end(), 'B');
    cs = count(recipe.begin(), recipe.end(), 'S');
    cc = count(recipe.begin(), recipe.end(), 'C');
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> money;
    ll l = 0, r = 1e12 + 100;
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
