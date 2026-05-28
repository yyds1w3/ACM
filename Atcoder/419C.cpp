//Fri Apr 24 04:15:09 PM CST 2026
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
    int n;
    std::cin >> n;
    int mnX = 1e9, mnY = 1e9;
    int mxX = 0, mxY = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        mnX = std::min(mnX, x);
        mnY = std::min(mnY, y);
        mxX = std::max(mxX, x);
        mxY = std::max(mxY, y);
    }
    std::cout << std::max((1 + mxX - mnX) / 2, (1 + mxY - mnY) / 2);
}
