//Thu May 28 04:13:53 PM CST 2026
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
            a[i] = std::min(a[i], n - 1); // i最多能涂的木板
        }
        std::sort(a.begin(), a.end());

        i64 ans = 0;
        std::vector<i64> suf(m + 1);
        for (int i = m - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + a[i];
        }
        for (int i = 0, j = m - 1; i < m; ++i) {
            j = std::max(i, j);
            while (j > i && a[i] + a[j] >= n) {
                j--;
            }
            //  n - a[j] <= k <= a[i]
            //  cnt = a[i] + a[j] - n + 1;
            ans += 1LL * (a[i] - n + 1) * (m - 1 - j);
            ans += suf[j + 1];
        }
        std::cout << 2 * ans << nl;
    }
}
