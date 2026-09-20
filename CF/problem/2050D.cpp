//Wed Jun 10 08:05:25 PM CST 2026
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
    std::string s;
    std::cin >> s;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        int idx = i;
        while (idx > 0 && s[idx] > s[idx - 1] + 1) {
            s[idx]--;
            std::swap(s[idx], s[idx - 1]);
            idx--;
        }
    }
    std::cout << s << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
