//Tue May 26 07:25:12 PM CST 2026
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
    std::string s;
    std::cin >> s;
    std::map<char, int> m;
    for (int i = 0; i < n; ++i) {
        m[s[i]]++;
    }
    for (int i = 1; i < n - 1; ++i) {
        if (m[s[i]] > 1) {
            std::cout << "YES" << nl;
            return;
        }
    }
    std::cout << "NO" << nl;

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
