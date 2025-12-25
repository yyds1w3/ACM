/**
 * Algorithm: Matrix Exponentiation (Optimized i-k-j)
 * Verified: Luogu P3390
 * Complexity: O(N^3 * log K)
 * Author: Qingw 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//============================start======================================
// 0 - based Matrix
struct Matrix {
    int n;
    int MOD;
    vector<vector<ll>> mat;

    Matrix(int _n, int _MOD) {
        n = _n;
        MOD = _MOD;
        mat.assign(n, vector<ll>(n, 0));
    }

    static Matrix identity(int n, int MOD) {
        Matrix res(n, MOD);
        for (int i = 0; i < n; ++i) {
            res.mat[i][i] = 1;
        }
        return res; 
    }

    Matrix operator* (const Matrix& other) const {
        Matrix res(n, MOD);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (mat[i][k] == 0) continue;
                for (int j = 0; j < n; ++j) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix qpow(Matrix a, ll b) {
    Matrix res = Matrix::identity(a.n, a.MOD);
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// ============================End=================================

int main() {
    IOS;
    
    ll n, k;
    cin >> n >> k;

    Matrix A(n, 1e9 + 7);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A.mat[i][j];
        }
    }
    Matrix ans = qpow(A, k);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans.mat[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
