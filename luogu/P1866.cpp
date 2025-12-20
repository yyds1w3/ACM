#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MAXN = 51;
const int MOD = 1e9 + 7;
int a[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i]; 
    }
    sort(a, a+n);
    ll ans = 1;
    for (int i = 0; i < n; ++i){
        ans = (ans * (a[i]-i)) % MOD;
    }
    cout << ans;
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
