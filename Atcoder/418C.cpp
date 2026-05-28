//Thu Apr 23 09:11:46 PM CST 2026
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
const int MAXV = 1e6;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> sum(MAXV + 1);
    std::vector<i64> cnt(MAXV + 1);
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        tot += x;
        sum[x] += x;
        cnt[x] += 1;
    }
    for (int i = 1; i <= MAXV; ++i) {
        sum[i] += sum[i - 1];
        cnt[i] += cnt[i - 1];
    }
    while (q--) {
        i64 b;
        std::cin >> b;
        i64 ans = 1 + sum[b - 1] + (n - cnt[b - 1]) * (b - 1);
        if (ans <= tot) {
            std::cout << ans << nl;
        }else {
            std::cout << -1 << nl;
        }
    }
}
