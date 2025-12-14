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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), cnt(n+1), pre(n+1);
    for (auto &i : a){
        cin >> i;
        cnt[i]++;
    }
    for (int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + cnt[i];
    }
    ll ans = 1;
    for (ll g = 1; g <= n; ++g){
        int t = min(n, 4*g-1);
        ll good = n - pre[t];
        if (g <= n) good+=cnt[g];
        if (2*g <= n) good+=cnt[2*g];
        if (3*g <= n) good+=cnt[3*g];
        if (good>= n-k) ans = g;
    }
    debug(ans);
    cout << ans << '\n';
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
         << chrono::duration<double, std::milli>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
