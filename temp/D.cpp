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
    int num;
    int i = 0;
    while (std::cin >> num) {
        i++;
        if (num == 250) {
            std::cout << i << nl;
            return 0;
        }
    }
}
