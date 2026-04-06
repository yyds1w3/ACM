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
    int n, i, h, r;
    std::cin >> n >> i >> h >> r;
    std::vector<int> a(n, h);
    std::map<std::pair<int, int>, bool> vis;
    for (int i = 0; i < r; ++i) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        if (r < l) std::swap(l, r);
        if (vis[std::make_pair(l, r)] == true) continue;
        vis[std::make_pair(l, r)] = true;
        for (int j = l + 1; j < r; ++j) {
            a[j]--;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << nl;
    }
}
