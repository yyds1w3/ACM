#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n;
struct st{
    int id;
    int t;
    bool operator<(st &other){
        if (t != other.t){
            return t < other.t;
        }else return id < other.id;
    }
}a[N];
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].t;
        a[i].id = i;
    }
    sort(a+1, a+1+n);
    double ans = 0;
    for (int i = 1; i <= n; ++i){
        ans += (n - i) * a[i].t;
        cout << a[i].id << " ";
    }
    cout << "\n" << setprecision(2) << fixed << ans / n;
}