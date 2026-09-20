//Tue Jun  9 07:49:28 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i][j] == '1') {
                pos[i]++;
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (v[i][j] == '0') {
                pos[i]++;
            }
        }
    }
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[pos[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) std::cout << ans[i] << " ";
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
