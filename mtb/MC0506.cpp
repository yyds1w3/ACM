//Sun Apr 26 10:50:23 AM CST 2026
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
const int MOD = 10007;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> L(n), R(n);
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                L[i]++;
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i]) {
                R[i]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            if (a[i] == a[j]) {
                ans = (ans + L[i] * R[j]) % MOD;
            }
        }
    }
    std::cout << ans << nl;
}
