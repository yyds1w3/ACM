//Wed Jul 22 03:47:19 PM CST 2026
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
    std::vector<int> a(n);
    std::set<i64> s;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    i64 sum = 0;
    s.insert(0);
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            sum += a[i];
        }else {
            sum -= a[i];
        }
        if (s.find(sum) == s.end()) {
            s.insert(sum);
        }else {
            std::cout << "YES" << nl;
            return;
        }
    }
    std::cout << "NO" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
