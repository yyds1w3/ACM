//Fri May  1 02:46:42 PM CST 2026
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
    void add(int pos, int val) {
        for (int i = pos + 1; i <= n; i += i & -i) { 
            treeA[i] += val;
        }
    }
    void update(int pos, int val) {
        int x = val - query(pos, pos + 1);
        for (int i = pos + 1; i <= n; i += i & -i) {
            treeA[i] += x;
        }
    }
    // sum(pos) == S[0, pos)
    i64 sum(int pos) {
        i64 res = 0;
        for (int i = pos; i > 0; i -= i & -i) { // 这里不加1 因为我们写的开区间
            res += treeA[i];
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
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<i64> pi(n);
        std::vector<i64> vals(n);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            if (i > 0) {
                pi[i] = pi[i - 1];
            }
            if (i & 1) {
                pi[i] -= x;
            }else {
                pi[i] += x;
            }
            vals[i] = pi[i];
        }
        std::sort(vals.begin(), vals.end());
        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
        auto rank = [&](i64 x) -> int {
            return std::lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        };
        int m = vals.size();
        Fenwick bit1(m), bit2(m);
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            int id = rank(pi[i]);
            if (i & 1) {
                ans += bit1.query(id + 1, m);
                bit2.add(id, 1);
            }else {
                ans += bit2.sum(id) + (pi[i] > 0);
                bit1.add(id, 1);
            }
        }
        std::cout << ans << nl;

    }
}
