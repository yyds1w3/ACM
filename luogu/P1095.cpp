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
    int M, S, T; cin >> M >> S >> T;
    int dp0 = 0, dp1 = 0;
    for (int i = 1; i <= T; ++i) {
        if (M >= 10) {
            dp0 += 60;
            M -= 10;
            dp1 += 17;
        }else {
            if (dp0 > dp1) dp1 = dp0;
            M += 4;
            dp1 += 17;
        }
        if (max(dp0, dp1) >= S) {
            cout << "Yes" << nl;
            cout << i << nl;
            return 0;
        }
    }
    cout << "No" << nl;
    cout << max(dp0, dp1) << nl;
}

