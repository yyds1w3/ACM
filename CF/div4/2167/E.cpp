//Tue May 12 09:24:32 PM CST 2026
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
        int n, k, x;
        std::cin >> n >> k >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        auto f = [&](int D) {
            std::vector<std::pair<int, int>> v;
            if (a[0] - D >= 0) {
                v.push_back({0, a[0] - D});
            }
            if (a[n-1] + D <= x) {
                v.push_back({a[n-1] + D, x});
            }
            for (int i = 0; i < n - 1; ++i) {
                if (a[i] + D <= a[i + 1] - D) {
                    v.push_back({a[i] + D, a[i + 1] - D});
                }
            }
            return v;
        };
        auto check = [&](int D) -> bool {
            i64 cnt = 0;
            for (auto [L, R] : f(D)) {
                cnt += (R - L + 1);
            }
            return cnt >= k;
        };
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) {
                l = mid;
            }else {
                r = mid - 1;
            }
        } 
        std::vector<int> ans;
        for (auto [L, R] : f(l)) {
            for (int j = L; j <= R; ++j) {
                ans.push_back(j);
            }
        }
        std::sort(ans.begin(), ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        for (int i = 0; i < k; ++i) std::cout << ans[i] << " ";
        std::cout << nl;
    }
}
