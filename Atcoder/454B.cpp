//Sat Apr 18 08:00:31 PM CST 2026
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
    int tot = 0;
    std::vector<bool> vis(m + 1);
    bool f1 = true;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (vis[x] == false) {
            vis[x] = true;
            tot++;
        }else {
            f1 = false;
        }
    }
    if (f1) std::cout << "Yes" << nl;
    else std::cout << "No" << nl;
    if (tot == m) std::cout << "Yes" << nl;
    else std::cout << "No" << nl;
}
