//Tue Apr 28 11:16:23 PM CST 2026
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
    // x -> x , [0, (x-1)/2];
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        auto check = [&](int x) -> bool {
            std::vector<int> cnt(n + 1);
            std::vector<int> v;
            for (int i = 0; i < n; ++i) {
                if (a[i] < x && !cnt[a[i]]) {
                    cnt[a[i]] = 1;
                }else {
                    v.push_back(a[i]);
                }
            }
            int mex = 0;
            while (cnt[mex]) mex++;
            for (int val : v) {
                if (val > 2 * mex) {
                    mex++;
                    while(cnt[mex]) mex++;
                }
            }
            return mex >= x;
        };
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) {
                l = mid;
            }else {
                r = mid - 1;
            }
        }
        std::cout << l << nl;
    }
}
