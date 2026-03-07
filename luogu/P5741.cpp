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
const int MAXN = 1e3 + 5;
struct stu {
    string name;
    int ch, ma, en, sum;
} st[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) {
        cin >> st[i].name >> st[i].ch >> st[i].ma >> st[i].en;
        st[i].sum = st[i].ch + st[i].ma + st[i].en;
    }
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            if (abs(st[i].ch - st[j].ch) <= 5 && abs(st[i].ma - st[j].ma) <= 5 && abs(st[i].en - st[j].en) <= 5 && abs(st[i].sum - st[j].sum) <= 10)
                cout << st[i].name << " " << st[j].name << nl;
        }
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
