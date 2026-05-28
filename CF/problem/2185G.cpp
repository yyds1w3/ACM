//Tue May 12 07:28:20 PM CST 2026
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
    std::vector<int> cnt(1e6 + 1);
    std::vector<i64> gain(1e6 + 1);
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> a(n);
        std::vector<int> mex1(n), mex2(n);
        i64 tot = 0;
        for (int i = 0; i < n; ++i) {
            int l;
            std::cin >> l;
            for (int j = 0; j < l; ++j) {
                int x;
                std::cin >> x;
                a[i].push_back(x);
                cnt[x]++;
            }
            int m1 = 0;
            while (cnt[m1] > 0) m1++;
            int m2 = m1 + 1;
            while (cnt[m2] > 0) m2++;
            mex1[i] = m1;
            mex2[i] = m2;
            tot += m1;
            gain[m1] += m2 - m1;
            for (int x : a[i]) {
                cnt[x]--;
            }
        }
        
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int v : a[i]) cnt[v]++;
            for (int v : a[i]) {
                ans += 1LL * (n - 1) * tot;
                if (v < mex1[i] && cnt[v] == 1) {
                    ans -= 1LL * (n - 1) * (mex1[i] - v);
                }
                ans += gain[v];
            }
            for (int v : a[i]) cnt[v]--;
        }
        std::cout << ans << nl;
        for (int i = 0; i < n; ++i) {
            gain[mex1[i]] = 0;
        }
    }
}
