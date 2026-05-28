//Mon Apr 20 07:14:28 PM CST 2026
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

// 把数拆成一位一位的视角
// 反证法
void solve(){
    int x, y, z;
    std::cin >> x >> y >> z;
    for (int i = 0; i < 30; ++i) {
        if ((x >> i & 1) + (y >> i & 1) + (z >> i & 1) == 2) {
            std::cout << "No" << nl;
            return;
        }
    }
    std::cout << "Yes" << nl;
}

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
        solve();
    }
}
