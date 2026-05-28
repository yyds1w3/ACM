//Wed May 27 06:58:53 PM CST 2026
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
        i64 n, k;
        std::cin >> n >> k;
        std::vector<std::vector<i64>> a(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            i64 x;
            std::cin >> x;
            for (int j = 0; j < 63; ++j) {
                if (!((x >> j) & 1)) {
                    a[i].push_back(1LL << j);
                }else {
                    ans++;
                }
            }
            std::reverse(a[i].begin(), a[i].end());
        }
        // val : id
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
        for (int i = 0; i < n; ++i) {
            if (!a[i].empty()) {
                pq.push({a[i].back(), i});
                a[i].pop_back();
            }
        }
        while (k && !pq.empty()) {
            auto [val, id] = pq.top();
            pq.pop();
            if (k < val) break;
            k -= val;
            ans++;
            if (!a[id].empty()) {
                pq.push({a[id].back(), id});
                a[id].pop_back();
            }
        }
        std::cout << ans << nl;
    }
}
