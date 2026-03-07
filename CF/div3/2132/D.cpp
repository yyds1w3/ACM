#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
ll f(ll n) {
    if (n <= 0) return 0;
    if (n < 10) return (n) * (n + 1) / 2;
    ll p = 1;
    ll len = 0;
    ll temp = n;
    while (temp >= 10) {
        p *= 10;
        temp /= 10;
        len++;
    }
    ll d = temp; // 最高位
    ll r = n % p; // 剩下位
    return d * 45 * len * (p / 10) + d * (d - 1) / 2 * p + d * (r + 1) + f(r);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int t; cin >> t;
    while (t--) {
        ll k; cin >> k;
        ll w = 1, num = 9;
        while (k > w * num) {
            k -= w * num;
            w++, num *= 10;
        }
        k--;
        ll end = 1;
        for (int i = 0; i < w - 1; i++) {
            end *= 10;
        }
        end += k / w;
        ll ans = f(end - 1);
        string s = to_string(end);
        k %= w;
        for (int i = 0; i <= k; ++i) ans += s[i] - '0';
        cout << ans << nl;
    }
    
}
