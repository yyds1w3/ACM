#include <iostream>
using namespace std;
const int N = 1e4+1;
int A[N][4];
int main(){
    int n, a, b, g, k, x, y;
    cin >> n;
    for (int i = 1; i <= n ;++i){
        cin >> a >> b >> g >> k;
        A[i][0] = a; A[i][1] = b;
        A[i][2] = a + g; A[i][3] = b + k;
    }
    cin >> x >> y;
    int ans = -1;
    for (int i = 1; i <= n; ++i){
        if (x >= A[i][0] && x <= A[i][2] && y >= A[i][1] && y <= A[i][3]){
            ans = i;
        }
    }
    cout << ans;
}