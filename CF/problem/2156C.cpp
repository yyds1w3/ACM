//Tue May  5 05:11:55 PM CST 2026
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
    std::vector<int> a(n + 1);
    std::vector<int> cnt(n + 1);
    std::vector<int> pcnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        pcnt[i] = pcnt[i - 1] + cnt[i];
    }
    for (int g = n; g >= 1; --g) {
        int tot = n - pcnt[std::min(n, 4 * g - 1)];
        if (3 * g <= n) tot += cnt[3 * g];
        if (2 * g <= n) tot += cnt[2 * g];
        if (1 * g <= n) tot += cnt[1 * g];
        if (tot >= n - k) {
            std::cout << g << nl;
            return;
        }
    }
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
