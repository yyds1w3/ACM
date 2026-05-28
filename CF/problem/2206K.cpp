//Thu Apr 30 05:21:32 PM CST 2026
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
        std::string s;
        std::cin >> s;
        std::vector<int> cnt(10);
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - '0']++;
        }
        int ans = 0;
        for (int h1 = 0; h1 <= 1; h1++) {
            for (int h2 = (h1 == 1 ? 1 : 9); h2 >= 0; --h2) {
                for (int m1 = 5; m1 >= 0; --m1) {
                    for (int m2 = 9; m2 >= 0; --m2) {
                        std::vector<int> need(10);
                        need[h1]++;
                        need[h2]++;
                        need[m1]++;
                        need[m2]++;
                        int take = 1e9;
                        for (int i = 0; i < 10; ++i) {
                            if (need[i] > 0) {
                                take = std::min(take, cnt[i] / need[i]);
                            }
                        }
                        if (take > 0) {
                            for (int i = 0; i < 10; ++i) {
                                cnt[i] -= take * need[i];
                            }
                            ans += take;
                        }
                    }
                }
            }
        }
        std::cout << ans << nl;
    }
}
