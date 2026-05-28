//Sat May  9 11:01:53 AM CST 2026
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
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 1);
    std::string s;
    std::cin >> s;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && s[l] == s[r]) {
            r++;
        }
        if (s[l] == '0') {
            if (r - l == 1) {
                std::cout << "NO" << nl;
                return;
            }else {
                std::reverse(p.begin() + l, p.begin() + r);
            }
        }
    }
    std::cout << "YES" << nl;
    for (int v : p) {
        std::cout << v << " ";
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
    while (t--) {
        solve();
    }
}
