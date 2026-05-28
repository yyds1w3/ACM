//Sun May  3 05:22:54 PM CST 2026
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
        int n, m;
        std::cin >> n >> m;
        std::map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            cnt[x]++;
        }
        std::vector<std::pair<int, int>> monster(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> monster[i].first;
        }
        for (int i = 0; i < m; ++i) {
            std::cin >> monster[i].second;
        }
        std::sort(monster.begin(), monster.end(), [](auto& lhs, auto& rhs) {
            bool lfree = lhs.second > 0;
            bool rfree = rhs.second > 0;
            if (lfree != rfree) {
                return lfree > rfree;
            }else {
                return lhs.first < rhs.first;
            }
        });
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int blood = monster[i].first;
            int c = monster[i].second;
            auto it = cnt.lower_bound(blood);
            if (it != cnt.end()) {
                if (c > 0) {
                    cnt[std::max(it->first, c)]++;
                }
                it->second--;
                if (it->second == 0) {
                    cnt.erase(it);
                }
                ans++;
            }
        }
        std::cout << ans << nl;
    }
}
