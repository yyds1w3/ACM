//Fri May 15 07:36:33 PM CST 2026
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
        i64 k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        k = std::min(k, 12 + k % 2);
        while (k--) {
            std::vector<int> cnt(n + 1, 0);
            for (int x : a) {
                if (x <= n) {
                    cnt[x]++;
                }
            }
            int mex = 0;
            while (cnt[mex]) {
                mex++;
            }
            for (int i = 0; i < n; ++i) {
                if (a[i] <= n && cnt[a[i]] == 1) {
                    a[i] = std::min(a[i], mex);
                } else {
                    a[i] = mex;
                }
            }
        }
        i64 sum = 0;
        for (int x : a) {
            sum += x;
        }
        std::cout << sum << "\n";
    }
}
