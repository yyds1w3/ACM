//Mon May 11 05:44:40 PM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        int n, q;
        std::cin >> n >> q;
        int N = 1 << n;
        std::vector<int> a(N);
        std::vector<int> tree(2 * N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
            tree[i + N] = a[i];
        }
        for (int i = N - 1; i >= 1; --i) {
            tree[i] = tree[2 * i] ^ tree[2 * i + 1];
        }
        while (q--) {
            int b, c;
            std::cin >> b >> c;
            b--;
            int u = N + b;
            int delta = tree[u] ^ c;
            int ans = 0;
            for (int k = 0; k < n; ++k) {
                int v = u ^ 1;
                bool win = false;
                if (u < v) {
                    if ((tree[u] ^ delta) >= tree[v]) {
                        win = true;
                    }
                }else {
                    if ((tree[u] ^ delta) > tree[v]) {
                        win = true;
                    }
                }
                if (!win) {
                    ans += (1 << k);
                }
                u >>= 1;
            }
            std::cout << ans << nl;
        }

    }
}
