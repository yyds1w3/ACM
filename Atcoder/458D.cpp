//Sat May 16 08:09:05 PM CST 2026
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
    int x;
    std::cin >> x;
    int q;
    std::cin >> q;
    std::priority_queue<int> pq1; // 大
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq2; // 小
    pq1.push(x);
    while (q--) {
        int a, b;
        std::cin >> a >> b;
        pq1.push(a);
        pq1.push(b);
        if (pq2.empty()) {
            int x = pq1.top();
            pq1.pop();
            pq2.push(x);
        }
        while (pq1.size() > pq2.size()) {
            int x = pq1.top();
            int y = pq2.top();
            if (x <= y) {
                pq2.push(x);
                pq1.pop();
            }else {
                pq1.pop();
                pq2.pop();
                pq1.push(y);
                pq2.push(x);
            }
        }
        std::cout << pq2.top() << nl;
    }
}
