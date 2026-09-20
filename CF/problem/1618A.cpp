//Mon Jun 15 12:21:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    std::vector<int> b(7);
    for (int i = 0; i < 7; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            for (int k = i + 2; k < 7; ++k) {
                if (b[i] + b[j] + b[k] == b[6]) {
                    std::cout << b[i] << " " << b[j] << " " << b[k] << nl;
                    return;
                } 
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
