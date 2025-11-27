#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll a[200000];
int main(){
    map<ll, ll> m;
    ll n, c;
    cin >> n >> c;
    for (ll i = 0; i < n; ++i){
        cin >> a[i];
        m[a[i]]++;
        a[i] -= c;
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i){
        ans += m[a[i]];
    }
    cout << ans;

}