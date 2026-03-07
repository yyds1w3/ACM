#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXT =  1e5 + 26;
const int MOD = 1e9 + 7;
ll dp[MAXT];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    string s; cin >> s;
    int t; cin >> t;
    for (int i = 0; i <= t + 25; i++) dp[i] = 1;// a - 0 z - 25 ab - 26
    for (int i = 26; i <= t + 25; i++) {
        dp[i] = (dp[i - 26] + dp[i - 25]) % MOD;
    }
    ll ans = 0;
    for (char c : s) {
        ans = (ans + dp[t + c - 'a']) % MOD;
    }
    cout << ans << nl;
}
