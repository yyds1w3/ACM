//Thu Apr 16 05:31:43 PM CST 2026
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
    int head, n;
    std::cin >> head >> n;
    std::vector<int> val(100001);
    std::vector<int> nxt(100001);
    std::vector<bool> vis(10001);
    for (int i = 0; i < n; ++i) {
        int u, v, nx;
        std::cin >> u >> v >> nx;
        val[u] = v;
        nxt[u] = nx;
    }
    std::vector<int> a, b;
    for (int cur = head; cur != -1; cur = nxt[cur]) {
        if (!vis[std::abs(val[cur])]) {
            vis[std::abs(val[cur])] = true;
            a.push_back(cur);
        }else {
            b.push_back(cur);
        }
    }
    auto print = [&](std::vector<int>& vec) -> void {
        int n = vec.size();
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) std::cout << std::setfill('0') << std::setw(5) << vec[i] << " " << val[vec[i]] << " " << std::setw(5) << vec[i + 1] << nl;
            else std::cout << std::setfill('0') << std::setw(5) << vec[n - 1] << " " << val[vec[n - 1]] << " " << -1 << nl;
        }
    };
    print(a);
    print(b);
}
