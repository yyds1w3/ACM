//Sat Jun 20 04:29:49 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(k + 1);
    for (int i = 0; i < k; ++i) {
        int x, c;
        std::cin >> x >> c;
        cnt[x] += c;
    }
    std::vector<int> a;
    for (int i = 1; i <= k; ++i) {
        a.push_back(cnt[i]);
    }
    std::sort(a.rbegin(), a.rend());
    if (n >= k) {
        std::cout << std::accumulate(a.begin(), a.end(), 0LL) << nl;
    }else {
        std::cout << std::accumulate(a.begin(), a.begin() + n, 0LL) << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
