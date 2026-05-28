//Fri Apr 24 04:12:43 PM CST 2026
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
    int q;
    std::cin >> q;
    std::priority_queue<int> pq;
    while (q--) {
        int op;
        int x;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x;
            pq.push(-x); 
        }else {
            int x = pq.top();
            x = -x;
            pq.pop();
            std::cout << x << nl;
        }
    }
}
