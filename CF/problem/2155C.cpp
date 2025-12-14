// dp递推, 举例开始的方向并递推，然后检查序列是否合法
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 676767677;
const int N = 1e5 + 1;
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(x) 42
#endif

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int ans = 0;
    for (int r = 0; r < 2; ++r){
        vector<int> b(n);
        b[0] = r;
        // 递推
        for (int i = 1; i < n; ++i){
            // 0 == L, 1 == R;
            // a[i] + (1 - b[i-1] == a[i-1] + b[i];
            b[i] = 1 - (b[i-1] + a[i] - a[i-1]);
        }

        int mn = *min_element(b.begin(), b.end());
        int mx = *max_element(b.begin(), b.end());
        // 局部局限
        if (0 <= mn && mx <= 1){
            int cnt = 1 + accumulate(b.begin() + 1, b.end(), 0);
            // 终极验证
            if (cnt == a[0]){
                ans++;
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
