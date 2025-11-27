#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
struct st {
    long long A, K;
}T[N];
typedef long long ll;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> T[i].A >> T[i].K;
    }
    sort(T+1, T+n+1, [](st x, st y){return x.A + x.K < y.A + y.K;});
    ll ans = 0;
    ll yali = -1e18;
    for (int i = 1; i <= n; ++i){
        ans = max(ans, yali - T[i].K);
        yali += T[i].A;
    }

    cout << ans;
}