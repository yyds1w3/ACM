//Sat Jul 25 01:57:22 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int MOD = 1e9 + 7;
void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.size();
    int m = t.size();
    std::vector<i64> h(n + 1), p(n + 1);
    p[0] = 1; 
    for (int i = 0; i < n; ++i) {
        h[i + 1] = (h[i] * 131 + (s[i] - 'a')) % MOD;
        p[i + 1] = p[i] * 131 % MOD;
    }
    i64 target = 0;
    for (int i = 0; i < m; ++i) {
        target = (target * 131 + (t[i] - 'a')) % MOD;
    }
    std::vector<int> pos;
    for (int l = 1; l + m - 1 <= n; ++l) {
        int r = l + m - 1;
        if ((h[r] - (h[l - 1] * p[m] % MOD) + MOD ) % MOD == target) {
            pos.push_back(l);
        }
    }
    std::cout << pos.size() << nl;
    for (int i = 0; i < (int)pos.size(); ++i) {
        std::cout << pos[i] << " ";
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
