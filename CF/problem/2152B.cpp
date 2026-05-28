//Fri May  8 04:53:07 PM CST 2026
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
        int n, rk, ck, rd, cd;
        std::cin >> n >> rk >> ck >> rd >> cd;
        int ans = 1;
        if (rk < rd) {
            ans = std::max(rd, ans);
        }else if (rk > rd){
            ans = std::max(n - rd, ans);
        }
        if (ck < cd) {
            ans = std::max(cd, ans);
        }else if (ck > cd){
            ans = std::max(n - cd, ans);
        }
        std::cout << ans << nl;
    }
}
