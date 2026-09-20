//Thu Aug 13 01:18:03 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
const int MOD = 998244353;
i64 frac[200001];
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    std::vector<int> b;
    std::vector<bool> vis(2 * n + 1);
    for (int i = 0; i < 2 * n; i += 2) {
        int x, y;
        std::cin >> x >> y;
        if (x > y) std::swap(x, y);
        if (x == 0 && y != 0) {
            a.push_back(y);
            vis[y] = true;
        } else if (x > 0) {
            vis[x] = true;
            vis[y] = true;
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (!vis[i]) {
            b.push_back(i);
        }
    }
    std::vector<int> u = a;
    for (int x : b) u.push_back(x);
    std::sort(u.begin(), u.end());
    int d = 0;
    if (!u.empty()) {
        d = u[u.size() / 2 - 1];
    }
    int c1 = 0, c2 = 0;
    for (int x : a) {
        if (x > d) c1++;
        else c2++;
    }
    int c3 = std::max((int)b.size() - (int)a.size(), 0) / 2;
    i64 ans = frac[c2 + c3] * frac[c1 + c3] % MOD * qpow(2, c3) % MOD;
    std::cout << ans << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    frac[0] = 1;
    for (int i = 1; i <= 200000; ++i) {
        frac[i] = (frac[i - 1] * i) % MOD;
    }
    
    int t;
    std::cin >> t;
    while (t--) solve();
    
    return 0;
}
