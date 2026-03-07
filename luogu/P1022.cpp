#include <bits/stdc++.h>
#include <cctype>
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
const int MAXN = 1e5 + 5;
void solve() {
    string s; cin >> s;
    int sz = s.size();
    char zimu = 'a';
    int xishu = 0;
    int changshu = 0;

    int val = 0;
    bool has_val = false;
    int sign = 1;
    int side = 1;
    rep(i, 0, sz-1) {
        char c = s[i];
        if (isdigit(c)) {
            val = val * 10 + (c - '0');
            has_val = true;
        }else if (isalpha(c)) {
            if (!has_val) val = 1;
            zimu = c;
            xishu += val * sign * side;
            val = 0;
            has_val = false;
        }else {
            if (has_val) {
                changshu += val * sign * (-1) * side;
                val = 0;
                has_val = 0;
            }
            if (c == '=') {
                side = -1;
                sign = 1;
            }else if (c == '+') {
                sign = 1;
            }else if (c == '-') {
                sign = -1;
            }
        }
    }
    if (has_val) changshu += (-1) * val * side * sign;
    double ans = (double)changshu / xishu;
    if (abs(ans) < 1e-3) ans = 0.0;
    cout << zimu << "=" << setprecision(3) << fixed << ans << nl;
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
