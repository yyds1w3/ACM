//Sun May 31 03:31:10 PM CST 2026
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
    std::vector<int> p(n), d(n);
    for (int i = 0; i < n; ++i) {std::cin >> p[i]; p[i]--;}
    for (int i = 0; i < n; ++i) {std::cin >> d[i]; d[i]--;}
    std::set<int> have;
    for (int i = 0; i < n; ++i) {
        int idx = d[i];
        have.insert(idx);
        while (have.find(p[idx]) == have.end()) {
            have.insert(p[idx]);
            idx = p[idx];
        }
        std::cout << have.size() << " ";
    }
    std::cout << nl;
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
    while (t--) solve();
}
