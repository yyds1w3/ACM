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
const int MAXN = 1e6 + 5;
bool not_prime[MAXN];
int primes[MAXN];
int cnt;
void eulersieve(int n) {
    not_prime[0] = not_prime[1] = true;
    rep(i, 2, n) {
        if (!not_prime[i]) primes[++cnt] = i; // 把已经是质数的记录
        for (int j = 1; j <= cnt && i * primes[j] <= n; ++j) { // 质数的倍数是合数
            not_prime[i * primes[j]] = true; 
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    int n; cin >> n;
    eulersieve(1e6);
    rep(i, 1, n){
        ll x; cin >> x;
        ll r =sqrt(x);
        if (r * r == x && !not_prime[r]) cout << "YES" << nl;
        else cout << "NO"<< nl;
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
