//Thu Aug 20 08:22:19 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl; 
#define debugv(v, sz) std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;
#define debugvv(v, sz1, sz2) std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}
using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    std::vector<bool> vis(n + 1);
    for (int i = n; i >= 1; --i) {
        int cnt = 0;
        int idx = 0;
        for (int j = 2; j <= n; ++j) {
            if (i * j <= n) {
                if (vis[i * j]) cnt++;
                if (cnt == 1) idx = i * j;
            }else break;
        }
        if (cnt == 0) vis[i] = true;
        if (cnt == 1) {vis[i] = true; vis[idx] = false;}
    }
    int k = std::accumulate(vis.begin(), vis.end(), 0);
    std::cout << k << nl;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) std::cout << i << " ";
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
