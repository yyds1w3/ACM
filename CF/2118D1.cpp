//Sat Aug 22 04:49:45 PM CST 2026
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
    i64 n, k;
    std::cin >> n >> k;
    std::vector<std::pair<i64, i64>> p(n);
    for (int i = 0; i < n; ++i) std::cin >> p[i].first;
    for (int i = 0; i < n; ++i) std::cin >> p[i].second;
    std::sort(p.begin(), p.end());

    std::map<i64, std::vector<i64>> mp0, mp1;
    std::map<i64, i64> p2id;
    for (int i = 0; i < n; ++i) {
        p2id[p[i].first] = i;

        i64 id0 = (p[i].first + p[i].second) % k;
        mp0[id0].push_back(p[i].first);
        i64 id1 = ((p[i].first - p[i].second) % k + k) % k;
        mp1[id1].push_back(p[i].first);
    }
    std::vector<std::vector<int>> adj(2*n);
    for (int i = 0; i < n; ++i) {
        i64 id0 = (p[i].first + p[i].second) % k;
        i64 id1 = ((p[i].first - p[i].second) % k + k) % k;
        auto it0 = std::upper_bound(mp1[id1].begin(), mp1[id1].end(), p[i].first);
        if (it0 != mp1[id1].end()) {
            i64 idx0 = p2id[*it0];
            adj[2*i].push_back(2*idx0+1);
        }

        auto it1 = std::lower_bound(mp0[id0].begin(), mp0[id0].end(), p[i].first);
        if (it1 != mp0[id0].begin()) {
            it1--;
            i64 idx1 = p2id[*it1];
            adj[2*i+1].push_back(2*idx1);
        }
    }
    std::vector<std::vector<int>> radj(2*n);
    std::vector<bool> out(2*n);
    std::queue<int> q;
    for (int i = 0; i < 2 * n; ++i) {
        if (adj[i].size() == 0) {
            out[i] = true;
            q.push(i);
        }
        else radj[adj[i][0]].push_back(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : radj[u]) {
            out[v] = true;
            q.push(v);
        }
    }
    int qu;
    std::cin >> qu;
    while (qu--) {
        i64 x;
        std::cin >> x;
        i64 id = x % k;
        auto it = std::lower_bound(mp1[id].begin(), mp1[id].end(), x);
        if (it == mp1[id].end()) {
            std::cout << "YES" << nl;
        }else {
            i64 node = p2id[*it];
            if (out[2*node+1]) {
                std::cout << "YES" << nl;
            }else {
                std::cout << "NO" << nl;
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
