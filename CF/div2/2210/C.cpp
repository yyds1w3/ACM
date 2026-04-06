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
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int>a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                int rg = std::gcd(a[i], a[i + 1]);
                if (rg < a[i]) cnt++;
            }else if (i == n - 1) {
                int lg = std::gcd(a[i], a[i - 1]);
                if (lg < a[i]) cnt++;
            }else {
                int lg = std::gcd(a[i], a[i - 1]);
                int rg = std::gcd(a[i], a[i + 1]);
                int lm = std::lcm(lg, rg);
                if (lm < a[i]) cnt++;
            }
        }
        std::cout << cnt << nl;
    }
}
