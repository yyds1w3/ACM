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
struct Fenwick {
    int n;
    std::vector<i64> treeA;

    Fenwick(int n_ = 0) : n(n_) {
        treeA.assign(n + 1, 0);
    }
    void add(int pos, i64 val) {
        for (int i = pos + 1; i <= n; i += i & -i) {
            treeA[i] += val;
        }
    }
    i64 query(int pos) {
        i64 res = 0;
        for (int i = pos; i > 0; i -= i & -i) {
            res += treeA[i];
        }
        return res;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    Fenwick bit1(n);
    Fenwick bit2(n);
    for (int i = 0; i < m; ++i) {
        char op;
        std::cin >> op;
        if (op == 'U') {
            int pos, val;
            std::cin >> pos >> val;
            pos--;
            bit1.add(val, 1);
            bit2.add(val, val);
        }else {
            int c, s;
            std::cin >> c >> s;
            
        }
    }
}
