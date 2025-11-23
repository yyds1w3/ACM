#include <iostream>

using namespace std;
using ll = long long;
ll a[100000];
int main(){
    ll  n, x, ans = 0;
    cin >> n >> x;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < n-1; ++i){
        ll s = a[i] + a[i+1];
        if (s > x){
            a[i+1] -= s-x;
            ans += s-x;
        }
    }
    cout << ans;
    
}