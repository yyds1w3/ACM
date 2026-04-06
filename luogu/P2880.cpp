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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> hx(n, std::vector<int>(20)), hn(n, std::vector<int>(20));
    for (int i = 0; i < n; ++i) {
        std::cin >> hx[i][0];
        hn[i][0] = hx[i][0];
    }
    for (int k = 1; k < 20; ++k) {
        for (int i = 0; i + (1 << k) <= n; ++i) {
            hx[i][k] = std::max(hx[i][k - 1], hx[i + (1 << (k - 1))][k - 1]);
            hn[i][k] = std::min(hn[i][k - 1], hn[i + (1 << (k - 1))][k - 1]);
        }
    }
    debug(hx);
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        l--;
        int k = std::__lg(r - l);
        int mx = std::max(hx[l][k], hx[r - (1 << k)][k]);
        int mn = std::min(hn[l][k], hn[r - (1 << k)][k]);
        std::cout << mx - mn << nl;
    }

}
