//Sat May 23 09:00:25 PM CST 2026
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
constexpr int P = 998244353;

int norm(int x) {
    while (x < 0) x += P;
    while (x >= P) x -= P;
    return x;
}
template<class T>
T qpow(T a, i64 b) {
    T res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
struct Z {
    int x; // [0, P)

    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}

    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return qpow(*this, P-2);
    }
    Z& operator+=(const Z& rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z& operator-=(const Z& rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z& operator*=(const Z& rhs) {
        x = 1LL * x * rhs.x % P; // 相乘后数值大小超过了norm的范围
        return *this;
    }
    Z& operator/=(const Z& rhs) {
        return (*this) *= rhs.inv();
    }
    friend Z operator+(const Z& lhs, const Z& rhs) {Z res = lhs; res += rhs; return res;}
    friend Z operator-(const Z& lhs, const Z& rhs) {Z res = lhs; res -= rhs; return res;}
    friend Z operator*(const Z& lhs, const Z& rhs) {Z res = lhs; res *= rhs; return res;}
    friend Z operator/(const Z& lhs, const Z& rhs) {Z res = lhs; res /= rhs; return res;}
    friend std::istream &operator>>(std::istream& is, Z& a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream& os, const Z& a) {
        os << a.val();
        return os;
    }
};
Z C(i64 n, int m) {
    if (m < 0 || n < m) return 0;
    Z res = 1;
    for (int i = 1; i <= m; ++i) {
        res = res * Z(n - i + 1) / Z(i);
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int p;
        std::cin >> p;
        p--;
        adj[p].push_back(i);
    }
    std::vector<i64> c(n), d(n);
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    for (int i = 0; i < n; ++i) std::cin >> d[i];
    Z ans = 1;
    auto dfs = [&](auto self, int u) -> void {
        if (ans.val() == 0) return;
        for (int v : adj[u]) {
            self(self, v);
            c[u] += c[v];
        }
        ans *= C(c[u], d[u]);
        c[u] -= d[u];
    };
    dfs(dfs, 0);
    std::cout << ans << nl;
}
