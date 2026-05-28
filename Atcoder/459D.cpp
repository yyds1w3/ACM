//Sat May 23 08:33:16 PM CST 2026
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
        std::string s;
        std::cin >> s;
        int n = s.size();
        std::vector<int> cnt(26);
        int mx = 0;
        for (char c : s) {
            cnt[c - 'a']++;
            mx = std::max(mx, cnt[c - 'a']);
        }
        if (mx > (n + 1) / 2) {
            std::cout << "No" << nl;
        }else {
            std::cout << "Yes" << nl;
            std::vector<std::pair<int, char>> p;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    p.push_back({cnt[i], i + 'a'});
                }
            }
            std::sort(p.rbegin(), p.rend());
            std::string s1 = "";
            for (auto [count, ch] : p) {
                s1 += std::string(count, ch);
            }
            std::string ans(n, ' ');
            int idx = 0;
            for (int i = 0; i < n; i += 2) {
                ans[i] = s1[idx++];
            }
            for (int i = 1; i < n; i += 2) {
                ans[i] = s1[idx++];
            }
            std::cout << ans << nl;
        }
    }
}
