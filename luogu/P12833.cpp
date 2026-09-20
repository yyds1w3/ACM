//Fri Jun  5 05:19:07 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int N = 1e5;
const int MOD = 1e9 + 7;
i64 x[N], y[N], z[N];
void solve() {
    int n;
    std::cin >> n;
    n--;
    std::cout << z[n] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    x[0] = 1, y[0] = 0, z[0] = 0;
    x[1] = 0, y[1] = 1, z[0] = 0;
    for (int i = 2; i < N; ++i) {
        x[i] = (x[i - 1] + x[i - 2]) % MOD;
        y[i] = (y[i - 1] + y[i - 2]) % MOD;
        z[i] = (z[i - 1] + z[i - 2] + y[i - 2] * x[i - 1]) % MOD;
    }
    while (t--) solve();
}
