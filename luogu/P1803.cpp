#include <iostream>
#include <algorithm>
using namespace std;
struct st{
    int x;
    int y;
};
st a[1000000];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;++i){
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a+n, [](st q, st w){return q.y <= w.y;});
    int now = 0, ans = 0;
    for (int i = 0; i < n; ++i){
        if (a[i].x >= now){
            now = a[i].y;
            ans++;
        }
    }
    cout << ans;
}