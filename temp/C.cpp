#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int x, y;
    std::cin >> x >> y;
    int mx = std::max({0, x, y});
    int tot = std::max(x + y, 0);
    std::cout << mx << " " << tot << nl;
    if (tot == mx && tot == 0) {
        std::cout << "-_-" << nl;
        return 0;
    }
    if (tot > mx) {
        std::cout << "^_^" << nl;
    }else {
        std::cout << "T_T" << nl;
    }
    
}

