//Fri May 15 08:23:59 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::map<int, int> cnt1, cnt2;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        cnt1[x % k]++;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        cnt2[x % k]++;
    }
    for (auto [m, c] : cnt2) {
        if (cnt2[m] + cnt2[k - m % k] != cnt1[m] + cnt1[k - m % k]) {
            std::cout << "NO" << nl;
            return;
        }
    }
    std::cout << "YES" << nl;
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
