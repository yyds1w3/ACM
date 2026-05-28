//Sat May  2 08:11:54 PM CST 2026
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
const i64 MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    std::string s;
    std::cin >> s;
    int n = s.size();
    i64 c = 1;
    i64 ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            ans = (ans + (1 + c) * c / 2) % MOD;
            c = 1;
        }else {
            c++;
        }
    }
    ans = (ans + (1 + c) * c / 2) % MOD;
    std::cout << ans << nl;
}
