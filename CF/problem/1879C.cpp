//Sat May 23 07:30:12 PM CST 2026
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
    std::vector<i64> frac(2e5 + 1);
    frac[0] = 1;
    for (int i = 1; i <= 2e5; ++i) {
        frac[i] = frac[i-1] * i % P;
    }
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.size();
        int c = 1;
        i64 ans = 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                ans = (ans * c) % P;
                cnt += c - 1;
                c = 1;
            }else {
                c++;
            }
        }
        if (c > 1) {
            ans = (ans * c) % P;
            cnt += c - 1;
        } 
        std::cout << cnt << " " << (ans * frac[cnt]) % P << nl;
    }
}
