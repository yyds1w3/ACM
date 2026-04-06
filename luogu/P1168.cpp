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
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> mn;
    std::priority_queue<int> mx;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        mx.push(x);
        mn.push(mx.top());
        mx.pop();
        if (mx.size() < mn.size()) {
            mx.push(mn.top());
            mn.pop();
        }
        if (i % 2 == 0) {
            std::cout << mx.top() << nl;
        }
    }
}
