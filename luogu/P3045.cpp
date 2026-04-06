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

struct Cow {
    i64 p, c;
    int id;
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 n, k, m;
    std::cin >> n >> k >> m;
    std::vector<Cow> a(n);
    std::vector<bool> vis(n);
    auto cmpP = [](const Cow& a, const Cow& b) {return a.p > b.p;};
    auto cmpC = [](const Cow& a, const Cow& b) {return a.c > b.c;};
    std::priority_queue<Cow, std::vector<Cow>, decltype(cmpP)> pqP;
    std::priority_queue<Cow, std::vector<Cow>, decltype(cmpC)> pqC;
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pqD;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].p >> a[i].c;
        a[i].id = i;
        pqP.push(a[i]);
        pqC.push(a[i]);
    }
    int ans = 0;
    while (k > 0 && !pqC.empty()) {
        auto cow = pqC.top();
        pqC.pop();
        if (vis[cow.id]) continue;
        if (m >= cow.c) {
            m -= cow.c;
            vis[cow.id] = true;
            pqD.push(cow.p - cow.c);
            ans++;
            k--;
        }else {
            break;
        }
    }
    while (true) {
        while (!pqP.empty() && vis[pqP.top().id]) pqP.pop();
        while (!pqC.empty() && vis[pqC.top().id]) pqC.pop();
        if (pqP.empty() || pqC.empty()) break;
        i64 cost_A = pqP.top().p;
        i64 cost_B = pqC.top().c + (pqD.empty() ? 2e18 : pqD.top());
        i64 min_cost = std::min(cost_A, cost_B);
        if (m < min_cost) break;
        m -= min_cost;
        ans++;
        if (cost_A <= cost_B) {
            vis[pqP.top().id] = true;
            pqP.pop();
        } else {
            auto cow = pqC.top();
            pqC.pop();
            vis[cow.id] = true;
            
            pqD.pop();
            pqD.push(cow.p - cow.c);
        }
    }
    std::cout << ans << nl;


}
