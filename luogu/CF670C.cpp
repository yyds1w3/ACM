//Wed Jul 22 10:52:02 AM CST 2026
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
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;
    std::vector<int> b(m), c(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> c[i];
    }
    
    std::vector<int> d;
    d.insert(d.end(), a.begin(), a.end());
    d.insert(d.end(), b.begin(), b.end());
    d.insert(d.end(), c.begin(), c.end());
    std::sort(d.begin(), d.end());
    d.erase(std::unique(d.begin(), d.end()), d.end());
    auto f = [&](int x) {
        return std::lower_bound(d.begin(), d.end(), x) - d.begin();
    };
    
    int sz = d.size();
    std::vector<int> cnt(sz);
    for (int i = 0; i < n; ++i) {
        cnt[f(a[i])]++;
    }
    std::pair<int, int> p = {cnt[f(b[0])], cnt[f(c[0])]};
    int id = 0;
    for (int i = 1; i < m; ++i) {
        std::pair<int, int> pi = {cnt[f(b[i])], cnt[f(c[i])]};
        if (pi > p) {
            p = pi;
            id = i;
        }
    }
    std::cout << id + 1 << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
