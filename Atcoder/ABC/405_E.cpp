#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
constexpr int P = 998244353;
// -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
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
    int x;
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
        return qpow(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};
struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invFac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invFac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invFac.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n + 1; i <= m; ++i) {
            _fac[i] = _fac[i - 1] * i; 
        }
        _invFac[m] = _fac[m].inv();
        for (int i = m; i > n; --i) {
            _invFac[i - 1] = _invFac[i] * i;
            _inv[i] = _invFac[i] * _fac[i - 1];
        }
        n = m; 
    }
    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invFac(int m) {
        if (m > n) init(2 * m);
        return _invFac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z cnm(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invFac(m) * invFac(n - m);
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    Comb comb;
    Z res = 0;
    if (d == 0) res = comb.cnm(a + b + c, b);
    else {
        for (int i = 0; i <= c; ++i) {
            res += comb.cnm(a + b + i, b) * comb.cnm(c + d - 1 - i, d - 1);
        }
    }
    std::cout << res << nl;
}
