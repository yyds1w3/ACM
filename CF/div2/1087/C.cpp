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
int query(int x, int y) {
    std::cout << "?" << " " << x << " " << y << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= 2 * n - 2; i += 2) {
        if (query(i, i + 1) == 1) {
            std::cout << "! " << i << std::endl;
            return;
        }
    }
    if (query(2 * n - 1, 1) == 1 || query(2 * n - 1, 2) == 1) {
        std::cout << "! " << 2 * n - 1 << std::endl;
    }else {
        std::cout << "! " << 2 * n << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}
