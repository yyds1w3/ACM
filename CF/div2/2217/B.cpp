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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::cin >> k;
        k--;
        std::vector<int> cnt(n);
        int cnt1 = 0;
        for (int i = 0; i < k; ++i) {
            if (i > 0) {
                cnt[i] = cnt[i - 1];
            } 
            if (a[i] != a[k]) {
                if (cnt[i] % 2 == 0) {
                    cnt[i]++;
                    cnt1++;
                }
            }else {
                if (cnt[i] % 2 == 1) {
                    cnt[i]++;
                    cnt1++;
                }
            }
        }
        if (cnt1 % 2 == 1) {
            cnt1++;
        }
        int cnt2 = 0;
        for (int j = n - 1; j > k ; --j) {
            if (j < n - 1) {
                cnt[j] = cnt[j + 1];
            }
            if (a[j] != a[k]) {
                if (cnt[j] % 2 == 0) {
                    cnt[j]++;
                    cnt2++;
                }
            } else {
                if (cnt[j] % 2 == 1) {
                    cnt[j]++;
                    cnt2++;
                }
            }
        }
        if (cnt2 % 2 == 1) {
            cnt2++;
        }
        std::cout << std::max(cnt1, cnt2) << nl;
    }
}
