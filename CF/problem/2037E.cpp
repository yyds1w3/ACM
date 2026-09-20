//Wed Jun 17 08:11:20 PM CST 2026
#include <bits/stdc++.h>
#define nl std::endl 
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
int ask(int l, int r) {
    std::cout << "? " << l << " " << r << nl;
    int x;
    std::cin >> x;
    return x;
}
void solve() {
    int n;
    std::cin >> n;
    std::string s(n + 1, '0');
    bool f = false;
    int pre = 0;
    for (int i = 2; i <= n; ++i) {
        int now = ask(1, i);
        if (now > 0 && !f) {
            f = true;
            s[i] = '1';
            for (int j = 1; j < i - now; ++j) {
                s[j] = '1';
            }
        }else if (f) {
            if (now > pre) {
                s[i] = '1';
            }
        }
        pre = now;
    }
    if (!f) {
        std::cout << "! IMPOSSIBLE" << nl;
    }else {
        std::cout << "! " << s.substr(1) << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
