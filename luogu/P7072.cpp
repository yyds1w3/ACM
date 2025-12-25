#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
int a;
int cnt[601];
void solve() {
    int n, w; cin >> n >> w;
    for (int i = 1; i <= n; ++i){
        cin >> a;
        cnt[a]++;
        int ne = max(1, i * w / 100);
        int now = 0;
        for (int j = 600; j >= 0; --j){
            now += cnt[j];
            if (now >= ne){
                cout << j << " ";
                break;
            }
        }
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
