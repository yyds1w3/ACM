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
    int Q;
    std::cin >> Q;
    std::vector<std::pair<int, int>> v(Q);
    int head = 0, top = -1;
    while (Q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int c, x;
            std::cin >> c >> x;
            v[++top] = {c, x};
        }else {
            int k;
            std::cin >> k;
            i64 ans = 0;
            while (k && head <= top) {
                if (v[head].first <= k) {
                    k -= v[head].first;
                    ans += 1LL * v[head].first * v[head].second;
                    head++;
                }else {
                    v[head].first -= k;
                    ans += 1LL * v[head].second * k;
                    k = 0;
                }
            }
            std::cout << ans << nl;
        }
    }
}
