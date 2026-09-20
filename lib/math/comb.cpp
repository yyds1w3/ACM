#include <bits/stdc++.h>
using i64 = long long;
constexpr int MOD = 998244353;
const int N = 1e6;
struct Z {
    i64 x;
    Z() : x(0) {}
    Z(i64 x_) : x(x_ % MOD) {if (x < 0) x += MOD;}
    i64 val() {return x;}
    Z& operator+=(Z b) {if ((x += b.x) >= MOD) x -= MOD; return *this;}
    Z& operator-=(Z b) {if ((x -= b.x) < 0) x += MOD; return *this;}
    Z& operator*=(Z b) {x = x * b.x % MOD; return *this;}
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
    Z inv() const {return pow(MOD - 2);}
    Z& operator/=(Z b) {return *this *= b.inv();}
    friend Z operator+(Z a, Z b) {return a += b;}
    friend Z operator-(Z a, Z b) {return a -= b;}
    friend Z operator*(Z a, Z b) {return a *= b;}
    friend Z operator/(Z a, Z b) {return a /= b;}
    friend bool operator==(Z a, Z b) {return a.val() == b.val();}
    friend bool operator!=(Z a, Z b) {return !(a == b);}
};
std::ostream& operator<<(std::ostream& os, Z& rhs) {return os << rhs.val();}
Z fact[N+1], infact[N+1];
// N < MOD, 否则infact全为0
void initFact() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) fact[i] = fact[i-1] * i;
    infact[N] = fact[N].inv();
    for (int i = N-1; i >= 0; --i) infact[i] = infact[i+1] * (i+1);
}
Z comb(i64 n, i64 m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fact[n] * infact[n-m] * infact[m];
}
