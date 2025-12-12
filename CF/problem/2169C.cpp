#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
void solve(){
    int n;
    cin >> n;
    ll s = 0, mn = 0, bst = 0;
    for (ll i = 1; i <= n; ++i){
        int x;
        cin >> x;
        s += x;
        mn = min(mn, i*(i+1)-s);
        bst = max(bst, i*(i+1)-s-mn);
    }
    cout << s+bst << "\n";
}
int main() {
    IOS;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}