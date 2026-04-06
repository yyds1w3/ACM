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
    int h, w, q;
    std::cin >> h >> w >> q;
    while (q--) {
        int op, x;
        std::cin >> op >> x;
        if (op == 1) {
            std::cout << x * w << nl;
            h -= x;
        }else if (op == 2) {
            std::cout << x * h << nl;
            w -= x;
        }
    }
}

