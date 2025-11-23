#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct st{
    double m;
    double v;
};

st a[101];
int main() {
    int n, t;
    double ans = 0;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].m >> a[i].v;
    }    
    sort(a+1, a+n+1, [](st x, st y){return x.v / x.m > y.v / y.m;});
    for (int i = 1; i <= n; ++i){
        if (t >= a[i].m){
            t -= a[i].m;
            ans += a[i].v;
        }else if(t > 0 && t < a[i].m){
            ans += a[i].v / a[i].m * t;
            t = 0;
            break;
        }
    }
    cout << setprecision(2) << fixed << ans;
    

}
