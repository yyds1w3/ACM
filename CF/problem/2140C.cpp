//Mon May 18 02:11:04 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const i64 INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    // l odd r odd ==> r - l;
    // l odd r even ==> 2 * ar + r - (2 * al + l);
    // l even r odd ==> 2 * al - l - (2 * ar - r);
    // l even r even ==> r - l;
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<i64> a(n);
        i64 tot = 0;
        // a0 - a1 + a2 - a3;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (i & 1) tot -= a[i]; 
            else tot += a[i];
        }
        i64 ans = tot;
        if (n & 1) ans += n - 1;
        else ans += n - 2;

        i64 mnodd = INF, mxeven = -INF;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                ans = std::max(ans, tot + 2 * a[i] + i - mnodd);
                mxeven = std::max(mxeven, 2 * a[i] - i);
            }else {
                ans = std::max(ans, tot + mxeven - (2 * a[i] - i));
                mnodd = std::min(mnodd, 2 * a[i] + i);
            }
        }
        std::cout << ans << nl;
    }
    
}
