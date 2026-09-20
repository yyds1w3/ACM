//Sat Jun 20 02:52:46 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int P = 1e9 + 7;
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
void solve() {
    int n, x;
    std::cin >> n >> x;
    Z add = 0;
    std::vector<int> mul;
    for (int i = 0; i < n; ++i) {
        char op;
        int num;
        std::cin >> op >> num;
        if (op == '+') add += num;
        else if (op == '-') add -= num;
        else if (op == 'x') {
            mul.push_back(num);
        }else if (op == '/') {
            mul.push_back(Z(num).inv().val());
        }
    }
    int m = mul.size();
    std::vector<Z> dp(m + 1);
    dp[0] = 1;
    for (int mu : mul) {
        for (int j = m; j >= 1; --j) {
            dp[j] += dp[j - 1] * mu;
        }
    }
    Z S = 0;
    for (int j = 0; j <= m; ++j) {
        S += dp[j] / comb.cnm(m, j);
    }
    S /= m + 1;
    std::cout << (Z(x) * dp[m] + add * S).val() << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
