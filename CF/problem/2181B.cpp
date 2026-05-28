//Sat May  2 02:07:10 PM CST 2026
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
        std::priority_queue<int> a, b;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            a.push(x);
        }
        for (int i = 0; i < m; ++i) {
            int x;
            std::cin >> x;
            b.push(x);
        }
        int turn = 0;
        while (!a.empty() && !b.empty()) {
            if (turn == 0) {
                int x = a.top();
                int y = b.top();
                b.pop();
                if (y > x) b.push(y-x);
            }else {
                int x = b.top();
                int y = a.top();
                a.pop();
                if (y > x) a.push(y-x);
            }
            turn ^= 1;
        }
        if (turn == 1) {
            std::cout << "Alice" << nl;
        }else {
            std::cout << "Bob" << nl;
        }
    }
}
