//Sun Jun  7 06:45:46 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].second >> a[i].first;
    }
    std::sort(a.rbegin(), a.rend());
    int ptr = 0;
    std::multiset<int> s;
    i64 mx = 0, cur = 0;
    std::vector<i64> pref(n + 1);
    for (int k = n; k >= 0; --k) {
        while (ptr < n && a[ptr].first >= k) {
            cur += a[ptr].second;
            s.insert(a[ptr].second);
            ptr++;
        }
        while (s.size() > k + 1) {
            cur -= *s.begin();
            s.erase(s.begin());
        }
        mx = std::max(mx, cur);
        pref[k] = (s.size() <= k ? cur : cur - *s.begin());
    }
    for (int k = 1; k <= n; ++k) pref[k] = std::max(pref[k], pref[k - 1]); 
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << std::max(mx, pref[y] + x) << nl;
    }
    

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
