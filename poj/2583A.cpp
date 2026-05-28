//Wed Apr 29 10:39:08 PM CST 2026
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
    
    int n;
    i64 d, m;
    std::cin >> n >> d >> m;
    std::vector<i64> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }
    std::sort(t.begin(), t.end());
    i64 target = m * d;
    i64 tot = 0;
    i64 cur = d;
    for (int i = 0; i < n; ++i) {
        tot += cur;
        if (tot >= target) {
            std::cout << i + 1 << nl;
            return 0;
        }
        cur -= t[i]; 
    }
    std::cout << -1 << nl;
    return 0;
}
