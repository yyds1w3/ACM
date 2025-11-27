#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[100001];
int b[100001];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(a+1, a+m+1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        int pos = lower_bound(a+1, a+m+1, b[i]) - a;

        int x = -1000000000, y = 1000000000;

        if(pos > 1) x = a[pos - 1]; 
        if(pos <= m) y = a[pos];    

        ans += min(b[i] - x, y - b[i]);
    }

    cout << ans;
    return 0;
}
