// 把n * n 变成了 2n*log2n
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(x) 42
#endif
void solve() {
    int n; cin >> n;
    vector<int> pos(2 * n + 1, 0);
    for (int i = 1; i <= n; ++i){
        int val; cin >> val;
        if (val <= 2*n) pos[val] = i;
    }
    ll ans = 0;
    for (int x = 1; x <= 2 * n; ++x){
        for (int y = x+1; (ll)x * y < 2 * n; ++y){
            if (pos[x] && pos[y]){
                if ((ll)x * y == pos[x] + pos[y]){
                    ans++;
                    debug(ans);
                }
            }
        }
    }
    cout << ans << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
