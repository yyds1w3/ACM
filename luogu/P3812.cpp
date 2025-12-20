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
ll p[64];
void insert(ll x){
    for (int i = 50; i >= 0; --i){
        if ((x >> i) & 1){
            if (!p[i]){
                p[i] = x;
                break;
            }else{
                 x ^= p[i];
            }
        }
    }
}
ll query(){
    ll ans = 0;
    for (int i = 50; i >= 0; --i){
        if ((ans ^ p[i]) > ans){
            ans ^= p[i];
        }
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        insert(x);
    }
    cout << query();
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
