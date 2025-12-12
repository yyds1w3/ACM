#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FELIX 0
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

const int N = 101;
int a[N], pre[N];
void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = max(pre[i-1], a[i]);
    }
    for (int i = n; i >= 1; --i){
        if (a[i] < pre[i]){
            cnt++;
        }
    }
    cout << cnt << '\n';
}
int main() {
    IOS;
#if FELIX
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int t; cin >> t;
    while (t--) solve();
#if FELIX
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - _clock_start).count() << "ms." << endl;
#endif
    return 0;
}