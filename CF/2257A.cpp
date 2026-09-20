//Mon Aug 17 10:33:52 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<bool> vis(26);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        vis[std::tolower(s[0]) - 'a'] = true;
    }
    bool ok = true;
    for (int i = 0; i < m; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < (int)s.size(); ++j) {
            if (!vis[s[j] - 'A']) {
                ok = false;
            }
        }
    }
    if (ok) {
        std::cout << "YES" << nl;
    }else {
        std::cout << "NO" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
