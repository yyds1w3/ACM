#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
typedef long long ll;
ll ans;
int n, c, a[N];
int my_lower_bound(int n, int target){
    int l = 1, r = n + 1;
    while (l < r){
        int m = l + (r - l) / 2;
        if (a[m] >= target){
            r = m;
        }else{
            l = m + 1;
        }
    }
    return l;
}

int main(){
    cin >> n >> c;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; ++i){
        int p1 = my_lower_bound(n, a[i] + c);
        int p2 = my_lower_bound(n, a[i] + c + 1);
        ans += p2 - p1;
    }
    cout << ans;
}