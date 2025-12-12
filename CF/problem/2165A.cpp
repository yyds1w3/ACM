#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
const int N = 2e5 + 2;
int a[N];
void solve(){
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll ans = -mx;
    a[n+1] = a[1];
    for (int i = 1; i <= n; ++i){
        ans += max(a[i+1], a[i]);
    }
    cout << ans << '\n';
}
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}