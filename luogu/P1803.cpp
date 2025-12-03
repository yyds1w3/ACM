#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n;
struct st{
    int a, b;
    bool operator<(st & other) {return b < other.b;}
}sts[N];
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> sts[i].a >> sts[i].b;
    }
    sort(sts+1, sts+1+n);
    int now = 0, ans = 0;
    for (int i = 1; i <= n; ++i){
        if (sts[i].a >= now){
            now = sts[i].b;
            ans++;
        }
    }
    cout << ans;
}