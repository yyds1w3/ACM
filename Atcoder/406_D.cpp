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
    int h, w, n;
    std::cin >> h >> w >> n;
    std::map<int, std::set<int>> xr, yr;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        xr[x].insert(y);
        yr[y].insert(x);
    }
    int q;
    std::cin >> q;
    for (int _ = 0; _ < q; ++_) {
        int op, om;
        std::cin >> op >> om;
        om--;
        if (op == 1) {
            for (int y : xr[om]) {
                yr[y].erase(om);
            }
            std::cout << xr[om].size() << nl;
            xr[om].clear();
        }else {
            for (int x : yr[om]) {
                xr[x].erase(om);
            }
            std::cout << yr[om].size() << nl;
            yr[om].clear();
        }
    }
}
