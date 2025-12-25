// 当有三个数时
// (x1+x2)*(w1+w2) + (x1+x3)*(w1+w3) + (x2+x3)*(w2+w3) ==
// x1*(w1+w2+w3+w1) + x2(w1+w2+w3+w2) + x3(w1+w2+w3+w3) ==
// (x1+x2+x3)*(w1+w2+w3) + (x1w1+x2w2+x3w3)
// 当有四个数时
// (x1+x2)(w1+w2) + (x1+x3)(w1+w3) + (x1+x4)(w1+w4) + (x2+x3)(w2+w3) + (x2+x4)(w2+w4) + (x3+x4)(w3+w4) ==
// x1(w1+w2+w3+w4+2*w1) + .... ==
// (x1+x2+x3+x4)(w1+w2+w3+w4) + (k-2)(x1w1+x2w2+....+x_kw_k)
#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
ll n, m, c, p;
const int MAXN = 1e5 + 1;
const int MOD = 10007;
struct st{
    ll num, col;
}a[MAXN];
ll s[MAXN][2]; // s[col][p] 代表什么颜色的奇数偶数有多少个
ll s_x[MAXN][2];
ll s_w[MAXN][2];
ll s_wx[MAXN][2];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].num;
        a[i].num %= MOD;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].col;
        c = a[i].col;
        p = i % 2;
        s[c][p]++;
        s_x[c][p] = (s_x[c][p] + i) % MOD; // 编号的前缀和 x1 + x2 + ...
        s_w[c][p] = (s_w[c][p] + a[i].num) % MOD; // 数字的前缀和 w1 + w2 + ...
        s_wx[c][p] = (s_wx[c][p] + (ll) i * a[i].num) % MOD; // 编号和数字乘积的前缀和 x1w1 + x2w2 + ...
    }
    ll ans = 0;
    for (int c = 1; c <= m; ++c){
        for (int p = 0; p <= 1; ++p){
            ll k = s[c][p]; // 某个颜色的奇数/偶数共有多少个?
            if (k < 2) continue;
            ll t1 = (k - 2) % MOD * s_wx[c][p] % MOD; // (k - 2) * sum(x_i * w_i)
            ll t2 = (s_x[c][p] * s_w[c][p]) % MOD; // sum(x_i) * sum(w_i)
            ans = (ans + t1 + t2) % MOD;
        }
    }
    cout << (ans + MOD) % MOD << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
