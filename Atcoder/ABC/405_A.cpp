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
    int r, x;
    std::cin >> r >> x;
    if (x == 1) {
        if (r >= 1600 && r <= 2999) {
            std::cout << "Yes" << nl;
        }else {
            std::cout << "No" << nl;
        }
    }else {
        if (r >= 1200 && r <= 2399) {
            std::cout << "Yes" << nl; 
        }else {
            std::cout << "No" << nl;
        }
    }
}
