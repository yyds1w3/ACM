//Thu Sep 10 07:51:24 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    i64 n, k, m;
    std::cin >> n >> k >> m;
    std::vector<std::pair<int, int>> a(n);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq1, pq2;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq3;
    for (int i = 0; i < n; ++i) {
        int p, c;
        std::cin >> p >> c;
        a[i] = {p, c};
        pq1.push({p, i});
        pq2.push({c, i});
    }
    for (int i = 0; i < k; ++i) pq3.push(0);
    std::vector<bool> vis(n);
    int cnt = 0;
    while (!pq1.empty()) {
        auto [x, id1] = pq1.top();
        if (vis[id1]) {
            pq1.pop();
            continue;
        }
        auto [y, id2] = pq2.top();
        if (vis[id2]) {
            pq2.pop();
            continue;
        }
        auto d = pq3.top();
        if (x > y + d) {
            m -= y + d;
            pq2.pop();
            vis[id2] = true;
            pq3.pop();
            pq3.push(a[id2].first - y);
        }else {
            m -= x;
            pq1.pop();
            vis[id1] = true;
        }
        if (m >= 0) cnt++;
        else break;
    }
    std::cout << cnt << nl;
}
