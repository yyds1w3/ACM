//Wed Aug 26 12:34:56 PM CST 2026
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
const int INF = 1e9;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i] >> c[i];
    std::vector<std::vector<int>> adj(n), radj(n);
    std::vector<int> in(n), rin(n);
    // 是否独立
    auto check = [&](int i, int j) -> bool {
        i64 da = a[i] - a[j];
        i64 db = b[i] - b[j];
        i64 dc = c[i] - c[j];
        if (da == 0) {
            if (db == 0) return dc != 0;
            else return false;
        }else {
            return db * db - 4 * da * dc < 0;
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (check(i, j)) {
                if (c[i] > c[j]) {
                    adj[j].push_back(i);
                    radj[i].push_back(j);
                    in[i]++;
                    rin[j]++;
                }else {
                    adj[i].push_back(j);
                    radj[j].push_back(i);
                    in[j]++;
                    rin[i]++;
                }
            }
        }
    }
    std::vector<int> dist1(n), dist2(n);
    auto bfs1 = [&]() -> void {
        std::queue<int> q;
        for (int i = 0; i < n; ++i) if (in[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                in[v]--;
                dist1[v] = std::max(dist1[v], dist1[u] + 1);
                if (in[v] == 0) q.push(v);
            }
        }
    };
    auto bfs2 = [&]() -> void {
        std::queue<int> q;
        for (int i = 0; i < n; ++i) if (rin[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : radj[u]) {
                rin[v]--;
                dist2[v] = std::max(dist2[v], dist2[u] + 1);
                if (rin[v] == 0) q.push(v);
            }
        }

    };
    bfs1(), bfs2();
    for (int i = 0; i < n; ++i) {
        std::cout << dist1[i] + dist2[i] + 1 << " ";
    }
    std::cout << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
