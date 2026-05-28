//Sun May  3 10:03:21 PM CST 2026
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
const i64 MOD = 1e9 + 7;

struct Matrix {
    int n, m;
    i64 p;
    std::vector<std::vector<i64>> a;
    
    std::vector<i64>& operator[](int i) { return a[i]; }
    const std::vector<i64>& operator[](int i) const { return a[i]; }
    
    Matrix(int n_, int m_, i64 p_) {
        n = n_; m = m_; p = p_;
        a.resize(n, std::vector<i64>(m));
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
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        i64 n, a1, a2, x, y;
        std::cin >> n >> a1 >> a2 >> x >> y;
        Matrix base(1, 4, MOD);
        base[0] = {a1 * a1 % MOD, a2 * a2 % MOD, a1 * a1 % MOD, a2 * a1 % MOD};
        Matrix b(4, 4, MOD);
        b[0] = {1, 0, 0, 0};
        b[1] = {1, x * x % MOD, 1, x};
        b[2] = {0, y * y % MOD, 0, 0};
        b[3] = {0, 2 * x * y % MOD, 0, y};
        Matrix res = base * b.qpow(n-1);
        std::cout << res[0][0] << nl;
    }
}
