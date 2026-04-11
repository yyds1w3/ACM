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
    int n, s;
    std::cin >> n >> s;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x - cur > s) {
            std::cout << "No" << nl;
            return 0;
        }
        cur = x;
    }
    std::cout << "Yes" << nl;
}
