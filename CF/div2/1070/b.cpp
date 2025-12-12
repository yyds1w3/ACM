#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FELIX 0
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
void solve(){
    int n;
    cin >> n;
    string org;
    cin >> org;
    org += org;
    int mx = 0;
    int cnt = 0;
    for (int i = 0; i < org.length(); ++i){
        if (org[i] == '0'){
            cnt++;
            mx = max(mx, cnt);
        }else{
            cnt = 0;
        }
    }
    cout << mx << '\n';
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