#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 51;
int t, len, a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> len;
        for (int j = 1; j <= len; ++j){
            cin >> a[j];
        }
        sort(a+1, a+1+len);
        int ans = 0;
        for (int j = 1; j <= len/2; ++j){
            ans += a[len-j+1] - a[j];
        }
        cout << ans << '\n';
    }
    
}