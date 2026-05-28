//Tue May 19 02:25:55 PM CST 2026
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
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i] >> b[i];
        }
        debug(a);
        debug(b);
        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            bool f = true;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (a[j] <= a[i] && b[i] <= b[j]) {
                    f = false;
                    break;
                }
            }
            if (f) ans.push_back(i);
        }
        std::cout << ans.size() << nl;
        for (int i : ans) std::cout << i + 1 << " ";
        std::cout << nl;
    }
}
