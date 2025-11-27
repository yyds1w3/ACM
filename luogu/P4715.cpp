#include<bits/stdc++.h>
using namespace std;
struct st{
    int v;
    int id;
}a[128];
int main(){
    int n;
    cin >> n;
    int num = pow(2,n);
    for (int i = 0; i < num ; ++i){
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a, a+num / 2 , [](st x, st y) {return x.v < y.v;});
    sort(a + num / 2, a+ num, [](st x, st y) {return x.v < y.v;});
    if (a[num/2 - 1].v > a[num-1].v){
        cout << a[num-1].id+1;
    }else{
        cout << a[num/2 - 1].id + 1;
    }
}
