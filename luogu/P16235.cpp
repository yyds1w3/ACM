//2026-04-11 14:51:41
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
void solve() {
    int n;
    std::cin >> n;
    i64 ans = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        ans += val;
        mx = std::max(mx, val);
    }
    if (ans % 5 == 0 && mx <= ans / 5) {
        std::cout << "T" << nl;
    }else {
        std::cout << "F" << nl;
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
