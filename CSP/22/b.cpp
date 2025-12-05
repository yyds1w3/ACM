#include <bits/stdc++.h>
using namespace std;
int n, l, r, t;
int cnt;
int sum[601][601];
int main(){
    cin >> n >> l >> r >> t;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> sum[i][j];
            sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int dx1 = max(1, i-r);
            int dy1 = max(1, j-r);
            int dx2 = min(n, i+r);
            int dy2 = min(n, j+r);
            double s = sum[dx2][dy2] + sum[dx1-1][dy1-1] - sum[dx1-1][dy2] - sum[dx2][dy1-1];
            if (s  <= ((dx2 - dx1 + 1) * (dy2 - dy1 + 1)) * t){
                cnt++;
            }
        }   
    }
    cout << cnt;
}