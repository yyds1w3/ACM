//Thu May 21 01:59:54 PM CST 2026
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
const int INF = 1e9;

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
        int n, x;
        std::cin >> n >> x;
        x--;
        std::string s;
        std::cin >> s;
        int lf = -INF, rf = INF;
        for (int i = x - 1; i >= 0; --i) {
            if (s[i] == '#') {
                lf = i;
                break;
            }
        }
        for (int i = x + 1; i < n; ++i) {
            if (s[i] == '#') {
                rf = i;
                break;
            }
        }
        if (lf == -INF && rf == INF) {
            std::cout << 1 << nl;
        }else {
            std::cout << std::max(std::min(n - x, lf + 2), std::min(x + 1, n - rf + 1)) << nl;
        }
    }
}
