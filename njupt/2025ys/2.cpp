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
    int a, b, x, d;
    int ans1 = 0;
    cin >> a >> b >> x >> d;
    while (d--){
        x++;
        if (x == b){
            ans1++;
            x = a;
        }else if(x == a) ans1++;
    }
    cout << ans1 << " " << x;
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
