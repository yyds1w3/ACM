//Sat May  9 08:13:28 PM CST 2026
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
    i64 n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int l;
        std::cin >> l;
        for (int j = 0; j < l; ++j) {
            int x;
            std::cin >> x;
            a[i].push_back(x);
        }
    }
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }
    k--;
    for (int i = 0; i < n; ++i) {
        if (k < 1LL * c[i] * a[i].size()) {
            std::cout << a[i][k % a[i].size()] << nl;
            break;
        }else {
            k -= c[i] * a[i].size();
        }
    }
}
