#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
const int N = 2e5 + 2;
int a[N], pre[N], suf[N];
void solve(){
    int n;
    cin >> n;
    int p;
    pre[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = min(pre[i-1], a[i]);
    }
    suf[n+1] = 0;
    for (int i = n; i >= 1; --i){
        suf[i] = max(suf[i+1], a[i]);
    }
    for (int i = 1; i <= n-1; ++i){
        if (pre[i] > suf[i+1]){
            cout << "No" << "\n";
            return;
        }
    }
    cout << "Yes" << '\n';
}
int main() {
    IOS;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}