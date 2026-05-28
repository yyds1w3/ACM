//Tue May 19 07:09:22 PM CST 2026
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
        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            for (int j = 0; j < 4; ++j) {
                if (s[j] == '#') {
                    ans.push_back(j + 1);
                }
            }
        }
        for (int j = ans.size() - 1; j >= 0; --j) {
            std::cout << ans[j] << " ";
        }
        std::cout << nl;
    }
}
