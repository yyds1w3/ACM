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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    int offset = 0;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int p, x;
            std::cin >> p >> x;
            p--;
            a[(p + offset) % n] = x;
        }else if (op == 2) {
            int p;
            std::cin >> p;
            p--;
            std::cout << a[(offset + p) % n] << nl;
        }else if (op == 3) {
            int k;
            std::cin >> k;
            offset = (offset + k) % n;
        }
    }
}
