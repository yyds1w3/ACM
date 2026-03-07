#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m; cin >> n >> m;
    vector<ll> cnt(n + 1);
    for (int i = 1; i <= m; ++i) {
        ll a, b; cin >> a >> b;
        cnt[(a + b) % n]++;
    }
    ll ans = ll(m) * (m - 1) / 2; // all pairs
    for (auto e : cnt) {
        ans -= (ll)e * (e - 1) / 2; // parallel pairs
    }
    cout << ans << nl;
}
