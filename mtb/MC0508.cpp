//Sun Apr 26 11:24:05 AM CST 2026
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
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> cnt(1000001);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        int mx = 0;
        for (int i = l; i < r; ++i) {
            cnt[a[i]]++;
            if (cnt[a[i]] > mx) {
                mx = cnt[a[i]];
            }
        }
        for (int i = l; i < r; ++i) {
            cnt[a[i]]--; 
        }
        std::cout << mx << nl;
    }
}
