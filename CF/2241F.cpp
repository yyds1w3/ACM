//Thu Jul 23 08:02:59 PM CST 2026
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
    int c1 = 0;
    i64 tot = 0;
    bool bob = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') c1++;
        else {
            if (c1 & 1) bob = false;
            tot += c1;
        }
    }
    if (tot & 1) {
        bob = false;
    }else {
        int c0 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') c0++;
            else {
                if (c0 & 1) bob = false;
            }
        }
    }
    if (bob) std::cout << "Bob" << nl;
    else std::cout << "Alice" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
