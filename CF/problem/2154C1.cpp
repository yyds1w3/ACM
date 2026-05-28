//Wed May  6 10:43:02 PM CST 2026
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
    std::vector<std::vector<int>> fac(2e5 + 1);
    for (int i = 2; i <= 2e5; ++i) {
        if (!fac[i].empty()) continue; // prime --> i;
        for (int j = i; j <= 2e5; j +=i) {
            fac[j].push_back(i);
        }
    }
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        std::map<int, int> cnt;
        int ans = 2;
        for (int i = 0; i < n; ++i) {
            for (int x : fac[a[i]]) {
                if (cnt[x] > 0) {
                    ans = 0;
                }
                cnt[x]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int x : fac[a[i]]) {
                cnt[x]--;
            }
            for (int x : fac[a[i] + 1]) {
                if (cnt[x] > 0) {
                    ans = std::min(ans, 1);
                }
            }
            for (int x : fac[a[i]]) {
                cnt[x]++;
            }
        }
        std::cout << ans << nl;
    }
}
