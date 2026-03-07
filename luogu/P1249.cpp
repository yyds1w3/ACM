#include <bits/stdc++.h>
#include <vector>
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
int a[MAXN], c[MAXN];
int wei() {
    per(i, MAXN-1, 1) if (c[i] != 0) return i;
    return 0;
}
void cl() {
    memset(c, 0, sizeof(c));
}
void mult(int b) {
    cl();
    rep(i, 1, MAXN-1) {
        c[i] += a[i] * b;
        if (c[i] >= 10) {
            c[i+1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    rep(i, 1, MAXN-1) a[i] = c[i];
}
void print() {
    int w = wei();
    per(i, w, 1) cout << c[i];
}
void solve() {
    int n; cin >> n;
    vector<int> v;
    rep(i, 2, n) {
        v.push_back(i);
        n -=i;
    }
    int sz = v.size();
    while (n > 0){
        per(i, sz-1, 0) {
            v[i]++;
            n--;
            if (n==0) break;
        }
    }
    a[1] = 1;
    rep(i, 0, sz-1) {
        mult(v[i]); 
        cout << v[i] << " ";
    } 
    cout << nl;
    print();
    
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
