//Wed May  6 02:19:02 PM CST 2026
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
        int n;
        std::cin >> n;
        std::vector<int> a(n), b;
        std::map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (cnt[a[i]] == 0) {
                b.push_back(a[i]);
            }
            cnt[a[i]]++;
        }
        std::sort(b.begin(), b.end());
        int mx = b.back();
        b.pop_back();
        int mex = 0;
        if (mx == 0) mex++;
        i64 ans = 1LL * mx * n + mex;
        for (int v : b) {
            if (mex == v) {
                mex++;
            }
            if (mex == mx) {
                mex++;
            }
            ans += mex;
        }
        ans += mex * (n - 1 - b.size());
        std::cout << ans << nl;
    }
}
