#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
const int MOD = 998244353;
i64 comb[65][65];
i64 pow2[65];
void init() {
    pow2[0] = 1;
    for (int i = 1; i <= 64; ++i) {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
    for (int i = 0; i <= 64; ++i) {
        comb[i][0] = 1; 
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
        }
    }

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    init();
    while (t--) {
        i64 n, k;
        std::cin >> n >> k;
        if (k == 0) {
            std::cout << 0 << nl;
            continue;
        }
        int len = 64 - __builtin_clzll(n);
        i64 pre = 0;
        int cnt1 = 0;
        i64 ans = 0;
        for (int i = len - 1; i >= 0; --i) {
            int bit = (n >> i) & 1;
            if (bit == 1) { 
                // 0 
                int rem = k - cnt1;
                if (rem >= 0 && rem <= i){
                    ans = (ans + pre * comb[i][rem]) % MOD; // pre
                }
                if (rem >= 1 && i >= 1) {
                    ans = (ans + (pow2[i] - 1 + MOD) * comb[i-1][rem-1]) % MOD; // suff
                }
                // 1
                pre = (pre + pow2[i]) % MOD;
                cnt1++;
            }
        }
        if (cnt1 == k) {
            ans = (ans + pre) % MOD;
        }
        std::cout << ans << nl;
    }
}
