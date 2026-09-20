//Wed Jun 10 09:20:18 PM CST 2026
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
    if (s[0] == 's') s[0] = '.';
    if (s[n - 1] == 'p') s[n - 1] = '.';
    int c0 = std::count(s.begin(), s.end(), 'p');
    int c1 = std::count(s.begin(), s.end(), 's');
    if (c0 != 0 && c1 != 0) std::cout << "NO" << nl;
    else std::cout << "YES" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
