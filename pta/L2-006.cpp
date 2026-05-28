//Thu Apr 16 08:03:23 PM CST 2026
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
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> post(n), miid(n);
    for (int i = 0; i < n; ++i) std::cin >> post[i];
    for (int i = 0; i < n; ++i) std::cin >> miid[i];
    std::vector<int> L(n + 1), R(n + 1);
    auto dfs = [&](auto self, int pl, int pr, int ml, int mr) -> void {
        if (pl >= pr) return;
        int root = post[pr - 1];
        int len = 0;
        for (int i = ml; i < mr; ++i) {
            if (miid[i] == root) {
                len = i - ml;
                break;
            }
        }
        int right_len = (pr - pl - 1) - len;
        if (len > 0) {
            L[root] = post[pl + len - 1]; 
        }
        if (right_len > 0) {
            R[root] = post[pr - 2]; 
        }
        self(self, pl, pl + len, ml, ml + len);
        self(self, pl + len, pr - 1, ml + len + 1, mr);
    };
    dfs(dfs, 0, n, 0, n);
    std::queue<int> q;
    q.push(post[n - 1]);
    int idx = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        idx++;
        if (idx != n) std::cout << u << " ";
        else std::cout << u;
        if (L[u] != 0) q.push(L[u]);
        if (R[u] != 0) q.push(R[u]);
    }

}
