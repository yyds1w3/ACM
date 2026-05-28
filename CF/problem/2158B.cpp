//Tue May  5 03:54:36 PM CST 2026
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
        std::vector<int> cnt(2 * n + 1);
        std::vector<int> a;
        for (int i = 0; i < 2 * n; ++i) {
            int x;
            std::cin >> x;
            if (cnt[x] == 0) {
                a.push_back(x);
            }
            cnt[x]++;
        }
        int x = 0, y = 0, z = 0;
        for (int v : a) {
            if (cnt[v] & 1) x++;
            else if (cnt[v] % 4) y++;
            else z++;
        }
        int ans = x + 2 * y + 2 * z;
        if ((z & 1) && x == 0) {
            ans -= 2;
        }
        std::cout << ans << nl;
    }
}
