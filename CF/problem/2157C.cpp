#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x) 42
#endif
void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> mn(n+1, 0);
    vector<ll> mx(n+1, 0);
    vector<ll> a(n+1, 0);
    while (q--){
        ll c, l, r;
        cin >> c >> l >> r;
        for (int i = l; i <= r; ++i){
            if (c == 1) mn[i] = 1;
            else mx[i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i){
        if (mx[i] && mn[i]) a[i] = k + 1;
        else if (mx[i]) a[i] = i % k;
        else a[i] = k;
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
