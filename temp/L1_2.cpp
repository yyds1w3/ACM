#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    std::vector<int> cnt(101);
         cnt[1] = 1;
    for (int i = 2; i <= 100; ++i) {
        cnt[i] = cnt[i-1] + 2 * (2 * i - 1);
    }
    int n;
    char c;
    std::cin >> n >> c;
    int mx = 0;
    for (int i = 100; i >= 1; --i) {
        if (cnt[i] <= n) {
            mx = i;
            break;
        }
    }
    for (int i = mx; i >= 2; --i) {
        std::cout << std::string(mx - i, ' ') + std::string(2 * i - 1, c) << nl;
    }
    std::cout << std::string(mx - 1, ' ') + std::string(1, c) << nl;
    for (int i = 2; i <= mx; ++i) {
        std::cout << std::string(mx - i, ' ') + std::string(2 * i - 1, c) << nl;
    }
    std::cout << n - cnt[mx] << nl;
}
