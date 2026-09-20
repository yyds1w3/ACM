#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> mn;
    std::priority_queue<int> mx;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (mx.empty() || x > mx.top()) {
            mn.push(x);
        }else {
            mx.push(x);
            mn.push(mx.top());
            mx.pop();
        }
        if (mx.size() < mn.size()) {
            mx.push(mn.top());
            mn.pop();
        }
        if (i % 2 == 0) std::cout << mx.top() << nl;
    }
}
