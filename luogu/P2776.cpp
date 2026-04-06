#include <bits/stdc++.h>
using i64 = long long;
#define nl "\n"
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int n, m;
    if (!(std::cin >> n >> m)) return 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::queue<int>> qs(m);
    std::queue<int> q;
    std::vector<bool> in_q(m, false);
    int t;
    std::cin >> t;
    while (t--) {
        std::string op;
        std::cin >> op;
        if (op == "push") {
            int x;
            std::cin >> x;
            int g = a[x];
            if (!in_q[g]) {
                in_q[g] = true;
                q.push(g);
            }
            qs[g].push(x);
        } else if (op == "pop") {
            int g = q.front(); 
            std::cout << qs[g].front() << nl;
            qs[g].pop();
            if (qs[g].empty()) {
                in_q[g] = false;
                q.pop();
            }
        }
    }
    
    return 0;
}
