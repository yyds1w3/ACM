//Sat May  9 12:05:44 PM CST 2026
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
        std::string s;
        std::cin >> n >> s;
        std::map<int, int> pos;
        pos[0] = -1;
        int target = std::count(s.begin(), s.end(), 'a') - std::count(s.begin(), s.end(), 'b');
        if (target == 0) {
            std::cout << 0 << nl;
        }else {
            int pre = 0;
            int ans = 1e9;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'a') {
                    pre++;
                }else {
                    pre--;
                }
                if (pos.find(pre - target) != pos.end()) {
                    ans = std::min(ans, i - pos[pre - target]);
                }
                pos[pre] = i;
            }
            if (ans >= n) std::cout << -1 << nl;
            else std::cout << ans << nl;
        }
    }
}
