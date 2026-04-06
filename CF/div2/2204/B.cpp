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
    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int cnt = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            mx = std::max(mx, a[i]);
            if (a[i] >= mx) {
                cnt++;
            }
        }
        std::cout << cnt << nl;
    }
}
