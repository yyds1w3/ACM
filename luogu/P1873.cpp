#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 2e9 + 5;
const int H = 4e5;
typedef long long ll;
int n, m, a[N];
bool judge(int x){
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] > x){
            ans += a[i] - x;
        }
    }
    return ans >= m;
}

int bsearch(int n){
    int l = 0, r = n;
    while (l < r){
        int m = l + (r - l ) / 2 + 1;
        if (judge(m)){
            l = m ;
        }else{
            r = m - 1;
        }
    }
    return r;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cout << bsearch(H);

}