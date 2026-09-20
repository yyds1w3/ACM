//Fri May 29 09:17:12 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"

using i64 = long long;

struct Fenwick {
    int n;
    std::vector<int> treeA;
    
    void init(int n_) {
        n = n_;
        treeA.assign(n + 1, 0);
    }
    void add(int pos, int val) {
        for (int i = pos + 1; i <= n; i += i & -i) { 
            treeA[i] += val;
        }
    }
    int sum(int pos) {
        int res = 0;
        for (int i = pos; i > 0; i -= i & -i) { 
            res += treeA[i];
        }
        return res;
    }
    int query(int l, int r) {
        return sum(r) - sum(l);
    }
};

struct Command {
    char op;
    int l, r, d, p;
    int id;
};

inline int get_digit(unsigned int val, int d) {
    static const int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    return (val / p10[d - 1]) % 10;
}

void solve() {
    int n, m;
    if (!(std::cin >> n >> m)) return;
    
    std::vector<unsigned int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    std::vector<Command> cmds(m);
    int query_cnt = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> cmds[i].op;
        if (cmds[i].op == 'S') {
            std::cin >> cmds[i].l >> cmds[i].r;
            cmds[i].l--;
        } else {
            std::cin >> cmds[i].l >> cmds[i].r >> cmds[i].d >> cmds[i].p;
            cmds[i].l--;
            cmds[i].id = query_cnt++;
        }
    }
    
    std::vector<int> ans(query_cnt);
    std::vector<int> cur_digit(n);
    Fenwick bit[10];
    
    for (int d = 1; d <= 10; ++d) {
        for (int p = 0; p <= 9; ++p) {
            bit[p].init(n);
        }
        
        for (int i = 0; i < n; ++i) {
            cur_digit[i] = get_digit(a[i], d);
            bit[cur_digit[i]].add(i, 1);
        }
        
        for (int i = 0; i < m; ++i) {
            if (cmds[i].op == 'S') {
                int x = cmds[i].l;
                unsigned int y = cmds[i].r;
                
                int old_p = cur_digit[x];
                int new_p = get_digit(y, d);
                
                bit[old_p].add(x, -1);
                bit[new_p].add(x, 1);
                cur_digit[x] = new_p;
            } else {
                if (cmds[i].d == d) {
                    ans[cmds[i].id] = bit[cmds[i].p].query(cmds[i].l, cmds[i].r);
                }
            }
        }
    }
    
    for (int i = 0; i < query_cnt; ++i) {
        std::cout << ans[i] << nl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    if (std::cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
