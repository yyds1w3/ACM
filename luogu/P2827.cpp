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
    int n, m, q, u, v, t;
    std::cin >> n >> m >> q >> u >> v >> t;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::vector<std::queue<i64>> qu(3);
    for (int i = 0; i < n; ++i) {
        qu[0].push(a[i]);
    }
    i64 offset = 0;
    for (int i = 1; i <= m; ++i) {
        i64 mx = -2e18;
        int mx_id = -1;
        for (int j = 0; j < 3; ++j) {
            if (!qu[j].empty() && qu[j].front() > mx) {
                mx = qu[j].front();
                mx_id = j;
            }
        }
        qu[mx_id].pop();
        i64 real = mx + offset;
        if (i % t == 0) {
            std::cout << real << " ";
        }
        i64 L1 = real * u / v;
        i64 L2 = real - L1;
        offset += q;
        qu[1].push(L1 - offset);
        qu[2].push(L2 - offset);
    }
    std::cout << nl;
    int cnt = 0;
    while (!qu[0].empty() || !qu[1].empty() || !qu[2].empty()) {
        i64 mx = -2e18;
        int mx_id = -1;
        for (int j = 0; j < 3; ++j) {
            if (!qu[j].empty() && qu[j].front() > mx) {
                mx = qu[j].front();
                mx_id = j;
            }
        }
        qu[mx_id].pop();
        cnt++;
        if (cnt % t == 0) {
            std::cout << mx + offset << " ";
        }
    }
    std::cout << nl;
}
