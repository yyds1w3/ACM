#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FELIX 1
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
ll x, y, k;
bool check(ll ost){
    for (ll i = 0; i < x; ++i){
        ost -= ost / y;
        if (ost < y) break;
    }
    return ost >= k;
}
void solve(){
    cin >> x >> y >> k;
    ll l = 0, r = 1e12 + 1;
    while (l < r){
        ll mid = (l + r) / 2;
        if (check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if (r == 1e12 + 1) cout << "-1" << '\n';
    else cout << r << '\n';
}
int main() {
    IOS;
#if FELIX
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int t;
    cin >> t;
    while (t--) solve();
    

#if FELIX
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - _clock_start).count() << "ms." << endl;
#endif
    return 0;
}