//Fri Apr 24 04:24:10 PM CST 2026
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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> diff(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        l--;
        diff[l]++;
        diff[r]--;
    } 
    for (int i = 0; i < n; ++i) {
        if (i > 0) diff[i] += diff[i - 1];
        if (diff[i] & 1) {
            std::cout << t[i];
        }else {
            std::cout << s[i];
        }
    }
}
