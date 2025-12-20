// 区间筛
// 虽然r, l 数据范围是20 亿。 但是r -l 的数据范围是100万
// 我们用根号l下的质数来筛掉r-l里的合数即可， 注意质数开始筛的范围是第一个满足质数的倍数和p*p(之前的已经被筛掉了)的最大值
#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MAXN = 1e6 + 1;
bool not_preime[MAXN];
ll prime[MAXN];
void euler_sieve(int n){
    int cnt = 0;
    not_preime[0] = not_preime[1] = 1;
    for (ll i = 2; i <= n; ++i){
        if (!not_preime[i]) prime[cnt++] = i;
        for (ll p : prime){
            if (!p) break;
            if (1LL * i * p > n) break;
            not_preime[i * p] = true;
            if (i % p == 0) break;
        }
    }
}
void solve() {
    ll l, r;
    cin >> l >> r;
    euler_sieve(sqrt(r));
    memset(not_preime, 0, sizeof(not_preime));
    for (ll p : prime){
        if (p == 0) break;
        for (ll j = max((l + p - 1) / p * p, p * p); j <= r; j += p){
            not_preime[j - l] = true; 
        }
    }
    if (l == 1){
        not_preime[0] = true;
    }
    int cnt = 0;
    for (int i = 0; i <= r - l; ++i){
        if (!not_preime[i]){
            cnt++;
        }
    }
    cout << cnt << endl;

    
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
