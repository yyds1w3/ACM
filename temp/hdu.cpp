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
            treeA[i] = std::max(val, treeA[i]);
        }
    }
    // sum(pos) == S[0, pos)
    i64 sum(int pos) {
        i64 res = 0;
        for (int i = pos; i > 0; i -= i & -i) { // 这里不加1 因为我们写的开区间
            res = std::max(res, treeA[i]);
        }
        return res;
    }
    // query[l, r) = S[0, r) - S[0, l)
    i64 query(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N, M;
    while (std::cin >> N >> M) {
        Fenwick bit(N);
        for (int i = 0; i < N; ++i) {
            int x;
            std::cin >> x;
            bit.add(i, x);
        }
        for (int i = 0; i < M; ++i) {
            char op;
            std::cin >> op;
            if (op == 'Q') {
                int l, r;
                std::cin >> l >> r;
                l--;
                std::cout << bit.query(l, r) << nl;
            }else if (op == 'U') {
                int a, b;
                std::cin >> a >> b;
                a--;
                bit.add(a, b - bit.query(a, a + 1));
            }
        }
    }
}
