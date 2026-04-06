#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
struct st {
    int a, b, c; 
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, l;
    std::cin >> n >> l;
    std::vector<int> pos(l, 0);
    int lst = 0;
    int nxt = 0;
    pos[lst]++;
    for (int i = 1; i < n; ++i) {
        int d;
        std::cin >> d;
        nxt = (lst + d) % l;
        pos[nxt]++;
        lst = nxt;
    }
    if (l % 3 != 0) {
        std::cout << 0 << nl;
        return 0;
    }
    i64 ans = 0;
    for (int i = 0; i < l / 3; ++i) {
        ans += (i64)pos[i] * pos[i + l / 3] * pos[i + 2 * l / 3];
    }
    std::cout << ans << nl;


}
