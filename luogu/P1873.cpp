#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000000];
int n, m;

int now(int x){
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] > x)
            ans += a[i] - x;
    }
    return ans >= m;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int l = 1, r = 2e9;
    while (l <= r){
        int m = l - (l - r) / 2;
        if (now(m)){
            l = m+1;
        }else{
            r = m-1;
        }
    }
    cout << r;
}

