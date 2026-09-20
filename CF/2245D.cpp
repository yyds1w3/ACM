//Tue Aug 25 07:01:40 PM CST 2026
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
    std::vector<std::vector<int>> adj(2*n);
    std::vector<int> in(2*n);
    for (int i = 0; i < m; ++i) {
        int op, x, y;
        std::cin >> op >> x >> y;
        x--, y--;
        if (op == 1) { 
            adj[2*x+1].push_back(2*y);
            adj[2*y+1].push_back(2*x);
            in[2*y]++, in[2*x]++;
        }else {
            adj[2*x].push_back(2*y+1);
            adj[2*y].push_back(2*x+1);
            in[2*y+1]++, in[2*x+1]++;
        }
    }
    std::vector<int> a(2*n); // a[2*i] 如果i是正数至少的绝对值大小
    std::queue<int> q;
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (in[i] == 0) {
            q.push(i);
            a[i] = 0;
            cnt++;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            in[v]--;
            a[v] = std::max(a[v], a[u] + 1);
            if (in[v] == 0) {
                q.push(v);
                cnt++;
            }
        }
    }
    if (cnt != 2*n) {
        std::cout << "NO" << nl;
    }else {
        std::cout << "YES" << nl;
        for (int i = 0; i < n; ++i) {
            if (a[2*i]>a[2*i+1]) {
                std::cout << a[2*i] << " ";
            }else {
                std::cout << -a[2*i+1] << " ";
            }
        }
        std::cout << nl;
    }

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
