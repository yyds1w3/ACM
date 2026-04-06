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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> diff(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        l--;
        diff[l]++;
        diff[r]--;
    }
    int ans = diff[0];
    for (int i = 1; i < n; ++i) {
        diff[i] += diff[i - 1];
        ans = std::min(ans, diff[i]);
    }
    std::cout << ans << nl;
}
