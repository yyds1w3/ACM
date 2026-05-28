//Fri May 22 08:45:18 AM CST 2026
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
        int n;
        std::cin >> n;
        int mn = 1e9;
        std::priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            pq.push(x);
            mn = std::min(mn, x);
        }
        i64 ans = 0;
        while (!pq.empty()) {
            int mx = pq.top();
            if (mx == mn) {
                break;
            }
            if (mx == mn + 1 && (mn & 1)) {
                int c1 = 0;
                int c2 = 0;
                while (!pq.empty()) {
                    if (pq.top() & 1) c1++;
                    else c2++;
                    pq.pop();
                }
                if (mn == 1 && c1 > c2) {
                    ans += c2;
                }else {
                    ans += c1;
                }
            }else {
                pq.pop();
                if (mx & 1) {
                    mx++;
                }else {
                    mx /= 2;
                }
                ans++;
                mn = std::min(mn, mx);
                pq.push(mx);
            }
        }
        std::cout << ans << nl;
    }
}
