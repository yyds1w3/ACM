#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int a[N];
int my_lower_bound(int target, int n){
    int l = 1, r = n + 1;
    while (l < r){
        int m = l + (r - l) / 2;
        if (a[m] >= target){
            r = m;
        }else{
            l = m + 1;
        }
    }
    if (a[r] != target) return -1;
    return r;
}

int main(){
    int n, m, q;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> q;
        cout << my_lower_bound(q, n) << " ";
    }
    
}