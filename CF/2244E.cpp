//Wed Jul 22 08:30:41 PM CST 2026
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
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<int> pre(n + 1);
    for (int i = 1; i < n; ++i) {
        pre[i + 1] = pre[i] + (s[i] == s[i - 1]);
    }
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        int need = (pre[r] - pre[l] + 1) / 2;
        if (need <= k) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
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
