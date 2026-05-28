//Sat May 16 10:49:25 PM CST 2026
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

void solve() {
    i64 a, n;
    std::cin >> a >> n;
    int x1, x2;
    std::cin >> x1 >> x2;
    if (x1 > x2) std::swap(x1, x2);
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;
    pq.push(x1);
    pq.push(x2);
    bool f = true;
    i64 ans1 = -1, ans2 = 0;
    while (f) {
        i64 cur = pq.top();
        pq.pop();
        if (cur == 0 && ans1 == -1) {
            ans1 = 0;
            continue;
        }
        if (cur < a) { // 1e17
            if (cur * 10 + x1 < 2e18 )pq.push(cur * 10 + x1); // 1e18
            if (cur * 10 + x2 < 2e18 )pq.push(cur * 10 + x2);
            ans1 = cur;
        }else {
            ans2 = cur;
            f = false;
        }
    }
    if (ans1 != -1) {
        std::cout << std::min(a-ans1, ans2-a) << nl;
    }else {
        std::cout << ans2 - a << nl;
    }
}

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
        solve();
    }
}
