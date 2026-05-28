//Sun May 17 10:58:05 PM CST 2026
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
    i64 n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    std::vector<i64> mp(26);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        for (char c : s[i]) {
            mp[c - 'A']++;
        }
    }
    for (int i = 0; i < n; ++i) {
        bool f = true;
        i64 ans = 1e18;
        auto mpp = mp;
        for (int j = 0; j < 26; ++j) {
            mpp[j] *= m;
        }
        for (char c : s[i]) {
            mpp[c - 'A'] -= (m + 1);
            mp[c - 'A']--;
            if (mpp[c - 'A'] < 0) {
                f = false;
            }
        }
        for (int j = 0; j < 26; ++j) {
            if (mp[j] != 0) {
                ans = std::min(ans, mpp[j] / mp[j]);
            }
        }
        for (char c : s[i]) {
            mp[c - 'A']++;
        }
        if (f == false) {
            std::cout << -1 << " ";
        }else {
            std::cout << ans << " ";
        }
    }
}
