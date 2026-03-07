#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= ll(e); ++i)
#define per(i,e,s) for (ll i = e; i >= ll(s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
bool not_prime[MAXN];
vector<int> primes; 
int cnt[MAXN];
void sieve(int n) {
    rep(i, 2, n) {
        if (!not_prime[i]) primes.push_back(i);
        for (int k = 2*i; k <= n; k += i) not_prime[k] = true;
    }
}
void solve() {
    int n; cin >> n;
    sieve(n+1);
    if (n <= 2) cout << 1 << nl;
    else cout << 2 << nl;
    rep(i, 2, n+1) {
        if (!not_prime[i]) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << nl;
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
