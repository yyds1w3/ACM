/**
 * Algorithm: Difference Array (1D & 2D)
 * Verified: Luogu P2367
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

//============================start======================================
struct Diff1D{
    vector<ll> diff;
    int n;
    void init(int _n){
        n = _n;
        diff.assign(n + 2, 0);
    }
    void add(int l, int r, ll v){
        diff[l] += v;
        diff[r+1] -= v;
    }
    vector<ll> build(){
        vector<ll> a(n + 2);
        for (int i = 1; i <= n; ++i){
            a[i] = a[i-1] + diff[i];
        }
        return a;
    }
}diff1D;
struct Diff2D{
    vector<vector<ll>> diff;
    int n, m;
    void init(int _n, int _m){
        n = _n;
        m = _m;
        diff.assign(n + 2, vector<ll>(m + 2, 0));
    }
    void add(int x1, int y1, int x2, int y2, ll v){
        diff[x1][y1] += v;
        diff[x2+1][y1] -= v;
        diff[x1][y2 + 1] -= v;
        diff[x2 + 1][y2 + 1] += v; 
    }
    vector<vector<ll>> build(){
        vector<vector<ll>> a(n+2, vector<ll>(m+2, 0));
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                a[i][j] = a[i-1][j] + a[i][j-1] + diff[i][j] - a[i-1][j-1];
            }
        }
        return a;
    }
}diff2D;

// ============================End=================================

int main(){
    int n, p;
    cin >> n >> p;
    diff1D.init(n);
    int v;
    for (int i = 1; i <= n; ++i){
        cin >> v;
        diff1D.add(i, i, v);
    }
    int x, y, z;
    for (int i = 1; i <= p; ++i){
        cin >> x >> y >> z;
        diff1D.add(x, y, z);
    }
    ll ans = 0x3f3f3f3f;
    vector<ll> a = diff1D.build();
    for (int i = 1; i <= n;++ i){
        ans = min(ans, a[i]);
    }
    cout << ans;
}