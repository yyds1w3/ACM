//Sat Apr 25 10:48:43 PM CST 2026
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
        int n, m;
        std::cin >> n >> m;
        std::priority_queue<int> pq1, pq2;
        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            if (i & 1) pq1.push(x);
            else pq2.push(x);
        }
        bool f1 = false;
        bool f2 = false;
        for (int i = 1; i <= m; ++i) {
            int x;
            std::cin >> x;
            if (x & 1) {
                if (!pq1.empty()) {
                    int val = pq1.top();
                    if (!f1 || val > 0) {
                        pq1.pop();
                        f1 = true;
                    }
                }
            }else {
                if (!pq2.empty()) {
                    int val = pq2.top();
                    if (!f2 || val > 0) {
                        pq2.pop();
                        f2 = true;
                    }
                }
            }
        }
        i64 ans = 0;
        while (!pq1.empty()) {
            ans += pq1.top();
            pq1.pop();
        }
        while (!pq2.empty()) {
            ans += pq2.top();
            pq2.pop();
        }
        std::cout << ans << nl;
    }
}
