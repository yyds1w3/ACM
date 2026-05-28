//Sat May 16 10:33:25 PM CST 2026
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
    std::vector<int> c(3);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        c[x]++;
    }
    if (c[1] == c[2]) {
        std::cout << c[0] + c[1] << nl;
    }else if (c[1] > c[2]) {
        std::cout << c[0] + c[2] + (c[1] - c[2]) / 3 << nl;
    }else {
        std::cout << c[0] + c[1] + (c[2] - c[1]) / 3 << nl;
    }
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
