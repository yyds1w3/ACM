//Fri May 22 07:51:15 PM CST 2026
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
constexpr int P = 1e9 + 7;

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
}comb;

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
        int n, k;
        std::cin >> n >> k;
        int c1 = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            c1 += x;
        }
        Z ans = 0;
        for (int i = k / 2 + 1; i <= std::min(k, c1); ++i) {
            ans += comb.cnm(c1, i) * comb.cnm(n - c1, k - i);
        }
        std::cout << ans << nl;
    }
}
