//Fri Jun 12 04:00:05 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
constexpr int P = 1e9 + 7;
struct Z {
    int x;
    Z() : x(0) {}
    Z(i64 x_) : x(x_ % P) {if (x < 0) x += P;}
    int val() {return x;}
    Z& operator+=(Z b) {if ((x += b.x) >= P) x -= P; return *this;}
    Z& operator-=(Z b) {if ((x -= b.x) < 0) x += P; return *this;}
    Z& operator*=(Z b) {x = (i64)x * b.x % P; return *this;}
    Z pow(i64 b) const {
        Z res = 1;
        Z a = *this;
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    Z inv() const {return pow(P - 2);}
    Z& operator/=(Z b) {return *this *= b.inv();}
    friend Z operator+(Z a, Z b) {return a += b;}
    friend Z operator-(Z a, Z b) {return a -= b;}
    friend Z operator*(Z a, Z b) {return a *= b;}
    friend Z operator/(Z a, Z b) {return a /= b;}
    friend bool operator==(Z a, Z b) {return a.val() == b.val();}
    friend bool operator!=(Z a, Z b) {return !(a == b);}
};
struct DSU {
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            f[ry] = rx;
            siz[rx] += siz[ry];
        }
    }
    int size(int x) {
        return siz[find(x)];
    }
};
void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::queue<int> q;
    std::vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 1) {vis[i] = true; q.push(i);}
    }
    int cnt = 0;
    Z ans = 1;
    DSU dsu(n + 1);
    auto check = [&](int idx) -> i64 {
        return (i64)dsu.size(idx) * (i64)dsu.size(idx + 1);
    };
    while (!q.empty()) {
        cnt++;
        int u = q.front();
        q.pop();

        if (check(u) != a[u]) {
            std::cout << 0 << nl;
            return;
        }
        // [l, u] [u+1, r]
        // dsu[u] dsu[u+1]
        ans *= (dsu.size(u) + dsu.size(u+1) - 1);
        dsu.merge(u, u + 1);
        // lft[u ...]
        int lft = dsu.find(u) - 1;
        if (lft != -1 && !vis[lft] && check(lft) == a[lft]) {
            q.push(lft);
            vis[lft] = true;
        }
        // [u.. rgt];
        int rgt = dsu.find(u) + dsu.size(u) - 1;
        if (rgt != n && !vis[rgt] && check(rgt) == a[rgt]) {
            q.push(rgt);
            vis[rgt] = true;
        }
    }
    if (cnt < n) {
        std::cout << 0 << nl;
        return;
    }
    ans = ans.inv();
    for (int i = 0; i < n; ++i) {
        ans *= (i + 1);
    }
    std::cout << ans.val() << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
