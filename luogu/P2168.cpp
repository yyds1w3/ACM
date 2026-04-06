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
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({w[i], 0});
    }
    while ((pq.size() - 1) % (k - 1) != 0) {
        pq.push({0, 0});
    }
    i64 ans = 0;
    while (pq.size() > 1) {
        i64 sum_w = 0;
        int mx_h = 0;
        for (int i = 0; i < k; ++i) {
            auto [w, h] = pq.top();
            pq.pop();
            sum_w += w;
            mx_h = std::max(mx_h, h);
        }
        ans += sum_w;
        pq.push({sum_w, mx_h + 1});
    }
    std::cout << ans << nl;
    std::cout << pq.top().second << nl;
}
