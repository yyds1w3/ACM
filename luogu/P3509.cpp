//Sun Apr 19 08:34:43 PM CST 2026
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
    i64 n, k, m;
    std::cin >> n >> k >> m;
    std::vector<i64> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    int L = 0, R = k + 1;
    std::vector<int> nxt(n); 
    for (int i = 0; i < n; ++i) {
        while (R < n && p[i] - p[L] > p[R] - p[i]) {
            L++;
            R++;
        }
        if (p[i] - p[L] >= p[R - 1] - p[i]) {
            nxt[i] = L;
        }else {
            nxt[i] = R - 1;
        }
    }
    std::vector<int> ans(n);
    std::vector<int> temp(n);
    std::iota(ans.begin(), ans.end(), 0);
    while (m) {
        if (m & 1) {
            for (int i = 0; i < n; ++i) {
                temp[i] = nxt[ans[i]];
            }
            ans = temp;
        }
        for (int i = 0; i < n; ++i) {
            temp[i] = nxt[nxt[i]];
        }
        nxt = temp;
        m >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] + 1 << " ";
    }
}
