//Mon Apr 20 05:49:14 PM CST 2026
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int cnt = 0;
    // 0 -> left 1 -> right
    for (int r = 0; r < 2; ++r) {
        std::vector<int> b(n);
        b[0] = r;
        for (int i = 1; i < n; ++i) {
            b[i] = 1 - (b[i-1] + a[i] - a[i - 1]); // a[i] - a[i-1] == 1 ==> left left;
        }
        int mn = *std::min_element(b.begin(), b.end());
        int mx = *std::max_element(b.begin(), b.end());
        if (0 <= mn && mx <= 1) {
            int ans = 1 + std::count(b.begin() + 1, b.end(), 1);
            if (ans == a[0]) {
                cnt++;
            }
        }
    }
    std::cout << cnt << nl;
}

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
        solve();
    }
}
