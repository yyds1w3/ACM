//Thu May 21 04:55:25 PM CST 2026
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
        i64 n, m, l;
        std::cin >> n >> m >> l;
        std::vector<int> a(l);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            x--;
            a[x] = 1;
        }
        std::vector<int> b(m);
        for (int i = 0; i < l; ++i) {
            std::sort(b.begin(), b.end(), std::greater<int>());
            int k = std::min(m - 1, n);
            b[k]++;
            if (a[i]) {
                n--;
                *std::max_element(b.begin(), b.end()) = 0;
            }
        }
        std::cout << *std::max_element(b.begin(), b.end()) << nl;
    }
}
