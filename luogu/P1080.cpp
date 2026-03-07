#include <bits/stdc++.h>
#include <cassert>
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
const int MAXN = 4e3 + 5;
int a[MAXN], c[MAXN], mx[MAXN];
void cl(int a[]) {
    rep(i, 1, MAXN-1) a[i] = 0;
}
int wei(int a[]) {
    per(len, MAXN-1, 1) if (a[len] != 0) return len;
    return 1;
}
void print(int a[]) {
    int len = wei(a);
    per(i, len, 1) cout << a[i];
    cout << nl;
}
void mult(int b) {
    cl(c);
    rep(i, 1, MAXN-1) {
        c[i] += b * a[i];
        if (c[i] >= 10) {
            c[i+1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    rep(i, 1, MAXN-1) {
        a[i] = c[i];
    }
}
void div(int b) {
    cl(c);
    int la = wei(a);
    int remainder = 0;
    per(i, la, 1) {
        int cur = remainder * 10 + a[i];
        c[i] = cur / b;
        remainder = cur % b;
    }
}
bool les() {
    int lc = wei(c);
    int lmx = wei(mx);
    if (lc != lmx) return lc > lmx;
    per(i, lc, 1) if (c[i] != mx[i]) return c[i] > mx[i];
    return false;
}
struct st {
    int l, r;
    bool operator<(const st& other) {
        return l * r < other.l * other.r;
    }
}p[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n+1) cin >> p[i].l >> p[i].r;
    sort(p + 2, p + 2 + n);
    a[1] = 1;
    mult(p[1].l);
    rep(i, 2, n+1) {
        div(p[i].r);
        if (les()) {
            rep(i, 1, MAXN-1) mx[i] = c[i];
        } 
        mult(p[i].l);
    }
    print(mx);

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
