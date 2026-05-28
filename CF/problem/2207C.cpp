//Thu May 21 03:01:35 PM CST 2026
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
        int n, h;
        std::cin >> n >> h;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<i64> cnt(n);
        for (int i = 0; i < n; ++i) {
            int mx = a[i];
            for (int j = i - 1; j >= 0; --j) {
                mx = std::max(mx, a[j]);
                cnt[i] += h - mx;
            }
            mx = a[i];
            for (int j = i + 1; j < n; ++j) {
                mx = std::max(mx, a[j]);
                cnt[i] += h - mx;
            }
            cnt[i] += h - a[i];
        }
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = i;
            for (int j = i; j < n; ++j) {
                if (a[j] > a[k]) {
                    k = j;
                }
                ans = std::max(ans, cnt[i] + cnt[j] - cnt[k]);
            }
        }
        std::cout << ans << nl;
    }
}
