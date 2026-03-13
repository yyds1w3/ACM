#include <bits/stdc++.h>
using i64 = long long;
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
    Z(i64 x = 0) : x(norm(x % P)) {}

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
    friend std::ostream &operator<<(std::ostream& os, Z& a) {
        os << a.val();
        return os;
    }
};
