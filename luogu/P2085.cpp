#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;

struct Node {
    i64 val;
    int id;
    int x;
    bool operator>(const Node& rhs) const {
        return val > rhs.val;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    if (!(std::cin >> n >> m)) return 0;
    std::vector<i64> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i] >> c[i];
    }
    std::priority_queue<Node, std::vector<Node>, std::greater<>> pq;
    auto f = [&](int i, int x) -> i64 {
        return a[i] * x * x + b[i] * x + c[i];
    };
    for (int i = 0; i < n; ++i) {
        pq.push({f(i, 1), i, 1});
    }
    for (int i = 0; i < m; ++i) {
        auto [val, id, x] = pq.top();
        pq.pop();
        std::cout << val << (i == m - 1 ? "" : " ");
        pq.push({f(id, x + 1), id, x + 1});
    }
    std::cout << nl;

    return 0;
}
