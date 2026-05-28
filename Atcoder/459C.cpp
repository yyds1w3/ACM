//Sat May 23 08:06:26 PM CST 2026
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
    i64 N, Q;
    std::cin >> N >> Q;
    i64 off = 0;
    std::vector<i64> a(N + 1);
    std::vector<i64> cnt(Q + 1);
    cnt[0] = N;
    i64 mn = 0;
    int q = Q;
    while (q--) {
        i64 op, x;
        std::cin >> op >> x;
        if (op == 1) {
            a[x]++;
            cnt[a[x]]++;
            while (cnt[mn + 1] == N) {
                mn++;
            }
            if (mn - off >= 1) off++;
        }else {
            if (x + off > Q) std::cout << 0 << nl;
            else std::cout << cnt[x + off] << nl; 
        }
    }
    
}
