//Sun May  3 04:07:09 PM CST 2026
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
const i64 INF = 2e18;

struct Matrix {
    int n, m;
    std::vector<std::vector<i64>> a;

    std::vector<i64>& operator[](int i) {return a[i]; }
    const std::vector<i64>& operator[](int i) const {return a[i]; }

    Matrix(int n_, int m_) : n(n_), m(m_), a(n, std::vector<i64>(m, INF)) {}
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        assert(lhs.m == rhs.n);
        Matrix res(lhs.n, rhs.m);
        for (int i = 0; i < lhs.n; ++i) {
            for (int k = 0; k < lhs.m; ++k) {
                if (lhs[i][k] == INF) continue;
                for (int j = 0; j < rhs.m; ++j) {
                    res[i][j] = std::min(res[i][j], lhs[i][k] + rhs[k][j]);
                }
            }
        }
        return res;
    }
};
struct Swag {
    std::vector<std::pair<Matrix, Matrix>> s1, s2;
    
    Matrix identity() {
        Matrix res(2, 2);
        // 斜对角线是乘法(此处是+)的恒等元, 其余是加法(此处是min)的恒等源
        res[0][0] = 0; res[0][1] = INF;
        res[1][0] = INF; res[1][1] = 0;
        return res;
    }
    void push(Matrix x) {
        if (s1.empty()) {
            s1.push_back({x, x});
        }else {
            s1.push_back({x, x * s1.back().second});
        }
    }
    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                Matrix x = s1.back().first;
                s1.pop_back();
                if (s2.empty()) {
                    s2.push_back({x, x});
                }else {
                    s2.push_back({x, s2.back().second * x});
                }
            }
        }
        s2.pop_back();
    }
    Matrix query() {
        if (s1.empty() && s2.empty()) return identity();
        if (s1.empty()) return s2.back().second;
        if (s2.empty()) return s1.back().second;
        return s1.back().second * s2.back().second;
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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        Swag swag;
        i64 ans = INF;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            Matrix m(2, 2);
            m[0][0] = INF; m[0][1] = x;
            m[1][0] = 0;   m[1][1] = x;
            swag.push(m);
            if (i >= k) {
                swag.pop();
            }
            if (i >= k - 1) {
                Matrix w = swag.query();
                i64 dp0 = 0;
                i64 dp1 = (i - k >= 0) ? a[i - k] : INF;
                i64 cost = std::min(dp0 + w[0][1], dp1 + w[1][1]);
                ans = std::min(ans, cost);
            }
        }
        std::cout << ans << nl;
    }
    return 0;
}
