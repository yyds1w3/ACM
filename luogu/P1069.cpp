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
const int MAXN = 1e4 + 5;
void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    if (m1 == 1) {
        cout << 0 << nl;
        return;
    }
    map<int, int> target;
    for (int i = 2; i * i <= m1; ++i) {
        if (m1 % i == 0) {
            int cnt = 0;
            while (m1 % i == 0) {
                cnt++;
                m1 /= i;
            }
            target[i] = cnt * m2;
        }
    }
    if (m1 > 1) target[m1] = m2;
    int mn = INF;
    rep(i, 1, n) {
        int s; cin >> s;
        int mx = 0;
        bool possible = true;
        for (auto [p, cnt] : target) {
            if (s % p != 0) {
                possible = false;
                break;
            }
            int exp = 0;
            while (s % p == 0) {
                exp++;
                s /= p;
            }
            mx = max(mx, (cnt + exp - 1) / exp);
        }
        if (possible) mn = min(mn, mx);
    }
    if (mn == INF) {
        cout << -1 << nl;
    }else {
        cout << mn << nl;
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
