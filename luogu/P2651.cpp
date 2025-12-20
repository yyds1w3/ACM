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


void solve() {
    int n;
    cin >> n;
    ll son, mon;
    cin >> son >> mon;
    n-= 2;
    bool flag = !(son % mon);
    while (n--){
        ll son2;
        cin >> son2;
        if (flag) continue;
        son = (__int128)son * son2 % mon;
        if (!son){
            flag = 1;
        }
    }
    cout << (flag ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
