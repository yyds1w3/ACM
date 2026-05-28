//Fri May 15 08:48:38 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> u(n-1), v(n-1), deg(n);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        deg[u[i]]++; deg[v[i]]++;
    }
    if (n <= 2) {
        std::cout << 0 << nl;
        return;
    }
    std::vector<int> leaf(n);
    int totLeaf = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (deg[u[i]] == 1) {
            leaf[v[i]]++;
            totLeaf++;
        }
        if (deg[v[i]] == 1) {
            leaf[u[i]]++;
            totLeaf++;
        }
    }
    int mx = 0; 
    for (int i = 0; i < n; ++i) {
        mx = std::max(mx, leaf[i]);
    }
    std::cout << totLeaf - mx << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
