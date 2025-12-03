#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, x1, y_1, x2, y2, diff[N][N];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> x1 >> y_1 >> x2 >> y2;
        diff[x1][y_1]++;
        diff[x1][y2+1]--;
        diff[x2+1][y_1]--;
        diff[x2+1][y2+1]++;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            diff[i][j] = diff[i][j] + diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            cout << diff[i][j] << ' ';
        }
        cout << endl;
    }

}