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
const int INF = 0x3f3f3f3f;
int wei(int x) {
    int res = 0;
    while (x >>= 1) res++;
    return res;
}
void solve() {
    int a, b; cin >> a >> b;
    int ans1 = b - a;
    int ans2 = INF;
    for (int ap = a; ap <= b; ++ap) {
        int wb = wei(b);
        int bp = 0;
        for (int w = wb; w >= 0; --w) {
            int wap = (ap >> w) & 1;
            int wb = (b >> w) & 1;
            if (wap == 1 && wb == 1) bp |= 1 << w;
            else if (wap == 1 && wb == 0) {bp |= 1 << w; break;}
            else if (wap == 0 && wb == 1) bp |= 1 << w;
            else if (wap == 0 && wb == 0) bp |= 0 << w;
        }
        ans2 = min(ans2, 1-a-b + ap + (ap | bp));
    }
    cout << min(ans1, ans2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
