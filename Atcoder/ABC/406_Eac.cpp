#include <iostream>

using namespace std;
using i64 = long long;

const int MOD = 998244353;

i64 comb[65][65];
i64 pow2[65];

void init() {
    // O(64) 预处理，绝对瞬间完成
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

void solve() {
    i64 n;
    int k;
    cin >> n >> k;
    
    if (k == 0) {
        cout << 0 << "\n";
        return;
    }
    
    // N >= 1 保证 __builtin_clzll 绝对不会触发 UB
    int len = 64 - __builtin_clzll(n);
    i64 pre = 0;
    int cnt1 = 0;
    i64 ans = 0;
    
    for (int i = len - 1; i >= 0; --i) {
        int bit = (n >> i) & 1;
        if (bit == 1) { 
            int rem = k - cnt1;
            
            // 0 分支 (平行宇宙)
            if (rem >= 0 && rem <= i) {
                ans = (ans + pre * comb[i][rem]) % MOD; 
            }
            if (rem >= 1 && i >= 1) {
                // 加强防护：内部先取一次模，彻底断绝任何溢出可能性
                i64 suff_val = (pow2[i] - 1 + MOD) % MOD;
                ans = (ans + suff_val * comb[i-1][rem-1]) % MOD;
            }
            
            // 1 分支 (回到现实)
            pre = (pre + pow2[i]) % MOD;
            cnt1++;
        }
    }
    
    if (cnt1 == k) {
        ans = (ans + pre) % MOD;
    }
    
    cout << ans << "\n";
}

int main() {
    // 竞速级 I/O 优化，防止 I/O 阻塞导致假性 TLE
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    init(); // 全局仅打表一次
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
