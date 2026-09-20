//Tue Aug  4 01:45:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::set<int>> s(3);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        s[x].insert(i + 1);
    }
    auto fir = [&](int x, int l, int r) -> int {
        auto it = s[x].lower_bound(l);
        if (it == s[x].end()) return r+1;
        if (*it > r) return r+1;
        return *it;
    };
    auto lst = [&](int x, int l, int r) -> int {
        auto it = s[x].upper_bound(r);
        if (it == s[x].begin()) return l-1;
        --it;
        if (*it < l) return l-1;
        return *it;
    };
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int p, x;
            std::cin >> p >> x;
            for (int i = 0; i < 3; ++i) s[i].erase(p);
            s[x].insert(p);
        }else {
            int l, r;
            std::cin >> l >> r;
            // 0 1 01; 1 2 12; 0 2 02;
            if (lst(0, l, r) <= fir(1, l, r) && lst(1, l, r) <= fir(2, l, r) && lst(0, l, r) <= fir(2, l, r)) {
                std::cout << 0 << nl;
                continue;
            }
            // 10 20 21
            int tl = fir(2, l, r);
            int tr = lst(0, l, r);
            int t1 = fir(1, l, r);
            if (t1 > r || tl > r || tr < l) {
                std::cout << 1 << nl;
                continue;
            }
            // 210
            int y = fir(1, tl, tr);
            if (y >= tl && y <= tr) std::cout << 2 << nl;
            else std::cout << 1 << nl;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
