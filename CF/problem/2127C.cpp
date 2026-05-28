//Thu May 21 01:22:11 PM CST 2026
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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n), b(n), p(n);
        std::iota(p.begin(), p.end(), 0);
        i64 tot = 0;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        for (int i = 0; i < n; ++i) {
            if (a[i] < b[i]) std::swap(a[i], b[i]);
            tot += a[i] - b[i];
        }
        std::sort(p.begin(), p.end(), [&](int i, int j) {
            if (b[i] != b[j]) {
                return b[i] < b[j];
            }else {
                return a[i] < a[j];
            }
        });
        int mn = 1e9;
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            l = b[p[i]];
            if (l <= r) {
                mn = 0;
                break;
            }else {
                if (r != -1) mn = std::min(l - r, mn);
            }
            r = std::max(r, a[p[i]]);
        }
        std::cout << tot + 2 * mn << nl;
    }
}
