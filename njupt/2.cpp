//Sat Aug  8 02:13:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        if (a < b) {
            std::swap(a, b);
        }
        int diff = a - b;
        a -= 2 * diff;
        b -= diff;
        if (a < 0 || b < 0) {
            std::cout << "" << nl;
        }else {
            if (a % 3 == 0) {
                std::cout << "" << nl;
            }else {
                std::cout << "" << nl;
            }
        }
    }
}
