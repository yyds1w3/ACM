//Mon Aug 24 02:43:56 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::priority_queue<int> pq1, pq2;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        pq1.push(x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        pq2.push(x);
    }
    int c = 1;
    while (!pq1.empty() && !pq2.empty()) {
        int u = pq1.top();
        pq1.pop();
        int v = pq2.top();
        pq2.pop();
        if (c & 1) {
            if (u < v) pq2.push(v - u);
            pq1.push(u);
        }else {
            if (v < u) pq1.push(u - v);
            pq2.push(v);
        }
        c++;
    };
    if (pq1.empty()) {
        std::cout << "Bob" << nl;
    }else {
        std::cout << "Alice" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
