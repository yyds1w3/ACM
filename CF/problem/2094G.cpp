//Thu May 14 02:10:44 PM CST 2026
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
        int q;
        std::cin >> q;
        i64 S = 0, R = 0;
        std::deque<int> dq;
        bool rev = false;
        while (q--) {
            int op;
            std::cin >> op;
            if (op == 1) {
                int an;
                if (!rev) {
                    an = dq.back();
                    dq.pop_back();
                    dq.push_front(an);
                }else {
                    an = dq.front();
                    dq.pop_front();
                    dq.push_back(an);
                }
                R += S - dq.size() * an;
            }else if (op == 2) {
                rev ^= 1;
                R = 1LL * (dq.size() + 1) * S - R;
            }else {
                int x;
                std::cin >> x;
                if (!rev) {
                    dq.push_back(x);
                }else {
                    dq.push_front(x);
                }
                S += x;
                R += 1LL * dq.size() * x;
            }
            std::cout << R << nl;
        }
    }
}
