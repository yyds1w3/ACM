//Wed Aug 26 09:13:46 PM CST 2026
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
const int INF = 2e9 + 1;
void solve() {
    int n, m, l;
    std::cin >> n >> m >> l;
    std::vector<int> odd, even;

    even.push_back(0);
    for (int i = 0; i < l; ++i) {
        int x;
        std::cin >> x;
        if (x & 1) odd.push_back(x);
        else even.push_back(x);
    }
    std::sort(odd.begin(), odd.end());
    std::sort(even.begin(), even.end());
    int mxodd, mxeven;
    if ((int)odd.size() & 1) {
        mxodd = std::accumulate(odd.begin(), odd.end(), 0) + std::accumulate(even.begin(), even.end(), 0);
        mxeven = mxodd - odd[0];
    }else {
        if (odd.empty()) {
            mxodd = 0;
            mxeven = std::accumulate(even.begin(), even.end(), 0);
        }else {
            mxodd = std::accumulate(odd.begin() + 1, odd.end(), 0) + std::accumulate(even.begin(), even.end(), 0);
            mxeven = mxodd + odd[0];
        }
    }
    // debugv(odd, odd.size());
    // debugv(even, even.size());
    // debug(mxodd);
    // debug(mxeven);
    std::vector<std::vector<int>> adj(n);
    std::vector<int> dist(2*n, INF);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int u;
        if (node & 1) u = (node - 1) / 2;
        else u = node / 2;

        for (int v : adj[u]) {
            int f = (dist[node] + 1) & 1;
            if (dist[2*v+f] > dist[node] + 1) {
                dist[2*v+f] = dist[node] + 1;
                q.push(2*v+f);
            }
        }
    }
    // debugv(dist, 2*n);
    for (int i = 0; i < n; ++i) {
        if (mxeven >= dist[2*i] || mxodd >= dist[2*i+1]) {
            std::cout << 1;
        }else {
            std::cout << 0;
        }
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
