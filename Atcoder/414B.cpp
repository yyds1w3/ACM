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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    i64 len = 0;
    std::vector<std::pair<char, i64>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first >> a[i].second;
        len += a[i].second;
        if (len > 100) {
            std::cout << "Too Long" << nl;
            return 0;
        }
    }
    std::string s;
    for (int i = 0; i < n; ++i) {
        s += std::string(a[i].second, a[i].first);
    }
    std::cout << s << nl;
}
