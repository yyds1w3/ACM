#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
int t, n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        ll ans = 0;
        int cnt = 0;
        int a, flag = 0;
        for (int j = 1; j <= n; ++j){
            cin >> a;
            if (a > 0 && flag == 1){
                cnt++;
                flag = 0;
            }
            if (a < 0){
                flag = 1;
            }
            ans += abs(a);
        }
        if (flag == 1) cnt++;
        cout << ans << " " << cnt << '\n';
    } 
    
}