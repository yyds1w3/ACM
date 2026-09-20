//Wed Jul 22 06:50:43 PM CST 2026
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
    std::string s;
    std::cin >> s;
    int cnt = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') cnt++;
        else cnt = 0;
        mx = std::max(mx, cnt);
    }
    std::cout << (mx + 1) / 2 << nl; 
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
