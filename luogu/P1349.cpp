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
struct Matrix {
    int n, m;
    int p;
    std::vector<std::vector<i64>> a;
    
    std::vector<i64>& operator[](int i) { return a[i]; }
    const std::vector<i64>& operator[](int i) const { return a[i]; }
    
    Matrix(int n_, int m_, int p_) {
        n = n_; m = m_; p = p_;
        a.resize(n, std::vector<i64>(m, 0));
    }
    Matrix& operator+=(const Matrix& rhs) {
        assert(n == rhs.n && m == rhs.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = (a[i][j] + rhs.a[i][j]) % p;
            }
        }
        return *this;
    }
    friend Matrix operator+(Matrix lhs, const Matrix& rhs) {
        lhs += rhs;
        return lhs;
    }
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        assert(lhs.m == rhs.n);
        Matrix res(lhs.n, rhs.m, lhs.p);
        for (int i = 0; i < lhs.n; ++i) {
            for (int k = 0; k < lhs.m; ++k) {
                if (lhs.a[i][k] == 0) continue;
                for (int j = 0; j < rhs.m; ++j) {
                    res.a[i][j] = (res.a[i][j] + lhs.a[i][k] * rhs.a[k][j]) % lhs.p;
                }
            }
        }
        return res;
    }
    Matrix& operator*=(const Matrix& rhs) {
        *this = *this * rhs; 
        return *this;
    }
    Matrix qpow(i64 b) const {
        assert(n == m);
        Matrix res(n, n, p);
        for (int i = 0; i < n; ++i) {
            res.a[i][i] = 1;
        }
        Matrix base = *this;
        while (b > 0) {
            if (b & 1) res *= base;
            base *= base;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int p, q, a1, a2, n, m;
    std::cin >> p >> q >> a1 >> a2 >> n >> m;
    Matrix base(1, 2, m);
    base[0][0] = a2 % m;
    base[0][1] = a1 % m;
    Matrix b(2, 2, m);
    b[0][0] = p % m;
    b[0][1] = 1 % m;
    b[1][0] = q % m;
    b[1][1] = 0 % m;
    if (n == 1) {
        std::cout << base[0][1] << nl;
    }else if (n == 2) {
        std::cout << base[0][0] << nl;
    }else {
        base *= b.qpow(n - 2);
        std::cout << base[0][0] << nl;
    }
}
