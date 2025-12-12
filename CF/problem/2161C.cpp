#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
const int N = 1e5;
int a[N];
void solve(){
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a+n);
    int l = 0, r = n-1;
    ll cost = 0;
    ll point = 0;
    vector<int> v;
    while (l <= r){
        if ((cost + a[r]) / x > cost / x){
            cost += a[r];
            point += a[r];
            v.push_back(a[r]);
            r--;
        }else{
            cost += a[l];
            v.push_back(a[l]);
            l++;
        }
    }
    cout << point << '\n';
    for (int y : v) cout << y << ' ';
    cout << '\n';
}
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}