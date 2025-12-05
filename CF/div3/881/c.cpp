#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
int t;
ll n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        ll ans = 0;
        while (n){
            ans += n;
            n >>= 1;
        }
        cout << ans << '\n';
    }
    
}