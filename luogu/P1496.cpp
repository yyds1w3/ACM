#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;

int get_id (vector<ll> &raw, int x){
    return lower_bound(raw.begin(), raw.end(), x) - raw.begin();
}
pair<ll,ll> a[20001];
void solve() {
    int n;
    cin >> n;
    vector<ll> raw(2*n+1, 0);
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
        raw[2*i-1] = a[i].first;
        raw[2*i] = a[i].second;
    }
    sort(raw.begin(), raw.end());
    raw.erase(unique(raw.begin(), raw.end()), raw.end());
    vector<ll> diff(raw.size() + 1, 0);
    for (int i = 1; i <= n; ++i){
        diff[get_id(raw, a[i].first)]++;
        diff[get_id(raw, a[i].second)]--;
    }
    ll ans = 0;
    int cur_cover = 0;
    for (uint i = 0; i < raw.size() - 1; ++i){
        cur_cover += diff[i];
        if (cur_cover > 0){
            ans += raw[i+1] - raw[i];
        }
    }
    cout << ans << endl;

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
