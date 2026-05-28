//Sat May  9 04:52:52 PM CST 2026
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
        int n, k, l, r;
        std::cin >> n >> k >> l >> r;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) std::cin >> v[i];
        auto a = v;
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < n; ++i) {
            a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        }
        std::vector<int> cnt1(v.size()), cnt2(v.size());
        int d1 = 0, d2 = 0;
        int p1 = 0, p2 = 0;
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            cnt1[a[i]]++;
            if (cnt1[a[i]] == 1) {
                d1++;
            }
            while (d1 > k) {
                cnt1[a[p1]]--;
                if (cnt1[a[p1]] == 0) d1--;
                p1++;
            }

            cnt2[a[i]]++;
            if (cnt2[a[i]] == 1) {
                d2++;
            }
            while (d2 > k - 1) {
                cnt2[a[p2]]--;
                if (cnt2[a[p2]] == 0) d2--;
                p2++;
            }
            // [p1, p2-1]
            int pl = std::max(p1, i - r + 1);
            int pr = std::min(p2 - 1, i - l + 1);
            ans += std::max(pr - pl + 1, 0);
        }
        std::cout << ans << nl;
    }
}
