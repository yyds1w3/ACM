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
    int n;
    std::cin >> n;
    std::vector<int> cnt(101);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        x = std::min(x, 100);
        for (int j = 0; j <= x; ++j) {
            cnt[j]++;
            if (cnt[j] >= j) {
                mx = std::max(mx, j);
            }
        }
    }
    std::cout << mx << nl;
}
