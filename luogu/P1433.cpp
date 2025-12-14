// 状态压缩
// dp： 无后效性, 但是我们多加了一个mask来代表另外一个状态, 吃掉了哪些奶酪
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
const double INF = 1e18;
double dis(pair<double, double> p1, pair<double, double> p2){
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
pair<double, double> a[16];
double dp[1 << 16][16];
void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    // Init
    for (int i = 0; i < (1 << n); ++i){
        for (int j = 0; j <= n; ++j){
            dp[i][j] = INF;
        }
    }
    // Init
    for (int i = 0; i <= n; ++i){
        dp[1 << i][i] = dis({0,0}, a[i]);
    }

    // Update dp status
    for (int mask = 1; mask <= (1 << n); ++mask){
        for (int i = 0; i < n; ++i){
            if (mask & (1 << i)){ // 如果当前奶酪被吃了
                if (dp[mask][i] == INF) continue; // 不可达
                for (int j = 0; j < n; ++j){
                    if (!(mask & (1 << j))){ // 如果下一个奶酪没被吃
                        int n_mask = mask | (1 << j);
                        double d = dis(a[i], a[j]); 
                        dp[n_mask][j] = min(dp[mask][i] + d, dp[n_mask][j]);
                    }
                }
            }
        }
    }
    double ans = INF;
    int full_mask = (1 << n) - 1;
    for (int i = 0; i < n; ++i){
        ans = min(ans, dp[full_mask][i]);
    }
    cout << setprecision(2) << fixed << ans;

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
    // cin >> tt;
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
