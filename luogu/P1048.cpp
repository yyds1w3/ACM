#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
int t, m, a, b;
int dp[N];
int main(){
    cin >> t >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        for (int j = t; j >= a; --j){
                dp[j] = max(dp[j], dp[j - a] + b);
        }
    }
    cout << dp[t];
}