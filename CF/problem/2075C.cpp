//Sun May 24 03:59:17 PM CST 2026
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
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> a[i];
        }
        std::vector<int> L(m), R(m);
        for (int i = 0; i < m; ++i) {
            L[i] = std::max(1 , n - a[i]);
            R[i] = std::min(a[i], n - 1);
        }
        std::vector<int> SL = L;
        std::sort(SL.begin(), SL.end());
        std::vector<i64> pi(m);
        for (int i = 0; i < m; ++i) {
            pi[i] = (i > 0 ? pi[i - 1] : 0) + SL[i];
        }
        i64 ans = 0;
        for (int i = 0; i < m; ++i) {
            int cnt = std::upper_bound(SL.begin(), SL.end(), R[i]) - SL.begin();
            if (cnt > 0)  {
                ans += (1 + R[i]) * cnt - pi[cnt-1];
            }
            if (R[i] >= L[i]) {
                ans -= R[i] - L[i] + 1;
            }
        }
        std::cout << ans << nl;
    }
}
