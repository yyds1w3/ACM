#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (i & 1) ans += x; 
    }
    cout << ans << nl;
}
