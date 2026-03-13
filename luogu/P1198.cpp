#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 m, d;
    std::cin >> m >> d;
    std::vector<std::pair<int, i64>> stk;
    i64 t = 0;
    int sz = 0;
    for (int i = 0; i < m; ++i) {
        char op;
        std::cin >> op;
        if (op == 'Q') {
            i64 l;
            std::cin >> l;
            int target = sz - l + 1;
            auto it = std::lower_bound(stk.begin(), stk.end(), std::make_pair(target, -2e18)); 
            t = it->second;
            std::cout << t << nl;
        }else if (op == 'A'){
            i64 n;
            std::cin >> n;
            n = ((n + t) % d + d) % d;
            sz++;
            while (!stk.empty() && stk.back().second <= n) {
                stk.pop_back();
            }
            stk.push_back({sz, n});
        }
    }
}
