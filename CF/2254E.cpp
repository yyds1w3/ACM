//Wed Aug  5 12:01:12 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    int n;
    std::cin >> n;
    std::multiset<i64> s;
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        i64 x;
        std::cin >> x;
        s.insert(x);
        tot += x;
    }
    if (tot <= 0) {
        std::cout << -1 << nl;
        return;
    }
    std::vector<i64> a(n);
    auto it = s.lower_bound(1);
    a[0] = *it;
    s.erase(it);

    // >= -diff 
    for (int i = 1; i < n; ++i) {
        auto it = s.lower_bound(1 - a[i-1]);
        a[i] = a[i-1] + *it;
        s.erase(it);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
