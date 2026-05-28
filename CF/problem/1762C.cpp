//Sun May 24 02:18:00 PM CST 2026
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
const int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    std::vector<int> p2(2e5 + 1);
    p2[0] = 1;
    for (int i = 1; i <= 2e5; ++i) {
        p2[i] = p2[i - 1] * 2 % P;
    }
    while (t--) {
        int n;
        std::cin >> n;
        std::string a;
        std::cin >> a;
        int L = 0; 
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || a[i] == a[i - 1]) {
                L++;
            }else {
                L = 1;
            }
            ans = (ans + p2[L - 1]) % P;
        }
        std::cout << ans << nl;
    }
}
